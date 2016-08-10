from django.views.generic import View
from django.core import serializers
from django.http import JsonResponse

from hubtubapp.models import Post, Hub

class PostsToJSON(View):
	"""
	Returns all Post objects with a given hub id as JSON.
	"""

	def find_posts(self, hub_id):
		posts = Post.objects.all().filter(hub=hub_id)
		return posts

	def get(self, request,  **kwargs):
		posts = self.find_posts(3)
		data = serializers.serialize("json", posts)
		return JsonResponse(data, safe=False)


class HubsToJSON(View):
	"""
	Returns all Hub objects as JSON.
	"""
	
	def find_hubs(self):
		hubs = Hub.objects.all()
		return hubs

	def get(self, request,  **kwargs):
		hubs = self.find_hubs()
		data = serializers.serialize("json", hubs)
		return JsonResponse(data, safe=False)	