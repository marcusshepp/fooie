from django.conf.urls import patterns, url

from .views import (	
    UserRegistrationView,
    Login,
    )


urlpatterns = patterns('',
    url(r'^register/$', UserRegistrationView.as_view(), name='register'),
    url(r'^login/$', Login.as_view(), name='register_login'),
 	url(r'^logout/$', 'django.contrib.auth.views.logout', {'next_page': '/'}, name='register_logout'),
 )