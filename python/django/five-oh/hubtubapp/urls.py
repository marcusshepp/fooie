from django.conf.urls import patterns, url, include
from django.contrib import admin
from django.contrib.auth import views as auth_views

from hubtubapp.views import (	
    HomeView,
    HubCreate,
    HubDelete,
    ViewAHub,
    HubPermission,
    )


urlpatterns = patterns('',
	url(r'^admin/', include(admin.site.urls)),
	url(r'^$', HomeView.as_view(), name='home'),
	url(r'^hub/create/$', HubCreate.as_view(), name='create'),
    url(r'^hub/(?P<pk>[-_\w]+)/detail/$', ViewAHub.as_view(), name='hubdetail'),
    url(r'^hub/(?P<pk>[-_\w]+)/delete/$', HubDelete.as_view(), name='hubdelete'),
    url(r'^hub/(?P<pk>[-_\w]+)/permission/$', HubPermission.as_view(), name='permission'),
	url(r'^account/', include('registration.urls')),
    url(r'^api/', include('api.urls')),
)
