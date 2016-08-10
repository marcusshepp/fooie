from django.conf.urls import patterns, url

from .views import (	
	PostsToJSON,
	HubsToJSON,
    )


urlpatterns = patterns('',
    url(r'^posts/$', PostsToJSON.as_view()),
    url(r'^hubs/$', HubsToJSON.as_view()),
)