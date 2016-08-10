from django.conf.urls import patterns, include, url
from django.contrib import admin
# from django.contrib.auth import views as auth_views

admin.autodiscover()

urlpatterns = patterns('',
	url(r'^$', include('hubtubapp.urls')),
	# url(r'^admin/', include(admin.site.urls)),
	url(r'^login/$', auth_views.login, {'template_name': 'hubtubapp/login.html'}, name='login'),
	# url(r'^logout/$', auth_views.logout, {'next_page': 'login'}, name='logout'),
#	url(r'^hub/', include('hubtubapp.urls')),
)