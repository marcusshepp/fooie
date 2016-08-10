from django.shortcuts import render_to_response
from django.utils.decorators import method_decorator
from django.http import HttpResponseRedirect
from django.contrib.auth.decorators import login_required
from django.core.urlresolvers import reverse_lazy, reverse
from django.core.exceptions import ValidationError
from django.views.generic.edit import FormView
from django.views.generic.detail import SingleObjectMixin
from django.views.generic import (
    View,
    TemplateView,
    ListView,
    CreateView,
    UpdateView,
    DeleteView,
    DetailView,
    FormView,
    )

from .models import Hub, Post
from .forms import HubForm, PostForm, SecretKey


class HomeView(View):
  
    template_name = 'hubtubapp/home.html'

    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(HomeView, self).dispatch(*args, **kwargs)

    def get(self, request, **kwargs):
        """ Returns all Hub objects that User is a member of. """
        hubs = Hub.objects.all().filter(members=request.user)
        return render_to_response(
            self.template_name, 
            {
            'object_list': hubs, 
            'user': request.user
            })


class HubCreate(CreateView):

    model = Hub
    form_class = HubForm

    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(CreateView, self).dispatch(*args, **kwargs)

    def form_valid(self, form):
        form.instance.admin = self.request.user
        return super(HubCreate, self).form_valid(form)


class HubDetail(DetailView):

    model = Hub
    template_name = 'hubtubapp/hub_detail.html'
    new_user = False

    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(HubDetail, self).dispatch(*args, **kwargs)

    def get(self, request, *args, **kwargs):
        """ If Hub not in User.hub_set() redirect to `HubPermission` """
        self.object = self.get_object()
        if self.object.public == False:
            if self.request.user not in self.object.members.all():
                return HttpResponseRedirect(reverse('permission', kwargs={'pk': self.get_object().id}))
            else:
                context = self.get_context_data(object=self.object)
                return self.render_to_response(context)
        else:
            if self.request.user not in self.object.members.all():
                self.object.members.add(self.request.user)
                self.object.save()
                self.new_user = True
            context = self.get_context_data(object=self.object)
            return self.render_to_response(context)
    
    def get_context_data(self, **kwargs):
        context = super(HubDetail, self).get_context_data(**kwargs)
        context['posts'] = Post.objects.all().filter(hub=self.get_object().id)
        context['form'] = PostForm()
        if self.new_user:
            context['welcome'] = "Welcome {0}, to {1}! We love you!".format(self.request.user.firstname, self.object.name)
        return context


class PostCreate(FormView, SingleObjectMixin):

    model = Hub
    form_class = PostForm
    template_name = "hubtubapp/hub_detail.html"
    
    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(PostCreate, self).dispatch(*args, **kwargs)

    def post(self, request, *args, **kwargs):
        if not request.user.is_authenticated():
            return HttpResponseForbidden()
        self.object = self.get_object() # do I need this line?
        return super(PostCreate, self).post(request, *args, **kwargs)

    def form_valid(self, form):
        form.instance.created_by = self.request.user
        form.instance.hub = self.get_object()
        form.save()
        return super(PostCreate, self).form_valid(form)

    def get_success_url(self):
        return reverse('hubdetail', kwargs={'pk': self.object.pk})


class ViewAHub(View):
    """
    Combines `HubDetail` and `PostCreate`
    into a single view.
    """

    def get(self, request, *args, **kwargs):
        view = HubDetail.as_view()
        return view(request, *args, **kwargs)

    def post(self, request, *args, **kwargs):
        view = PostCreate.as_view()
        return view(request, *args, **kwargs)


class HubPermission(FormView, SingleObjectMixin):
    """
    Handles adding/removing Users Hubs.
    Prompts for `secret key`.
    """
    
    model = Hub
    form_class = SecretKey
    template_name = 'hubtubapp/secret_key.html'

    def get_context_data(self, **kwargs):
        context = {}
        context['form'] = self.form_class
        return context        

    def get_success_url(self):
        return reverse('hubdetail', kwargs={'pk': self.get_object().pk})

    def post(self, request, *args, **kwargs):
        """ 
        Secret Key should match that field saved in Model definition. 
        Add Hub to user's Hub Set.
        Save User.
        """
        hub = self.get_object()
        if request.POST['secret_key'] == hub.secret_key:
            self.get_object().members.add(self.request.user)
            self.get_object().save()
            return HttpResponseRedirect(reverse('hubdetail', kwargs={'pk': self.get_object().pk}))
        else:
            raise ValidationError("Secret Key was incorrect", code="Secret Key was incorrect")


class HubUpdate(UpdateView):

    model = Hub
    fields = ['name']

    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(UpdateView, self).dispatch(*args, **kwargs)


class HubDelete(DeleteView):

    model = Hub
    success_url = reverse_lazy('home')

    @method_decorator(login_required)
    def dispatch(self, *args, **kwargs):
        return super(DeleteView, self).dispatch(*args, **kwargs)
