from datetime import date

from django.db import models
from django.conf import settings
from django.core.urlresolvers import reverse

from registration.models import User


class Hub(models.Model):
	""" Room object where discussions will take place. """

	class Meta:
		get_latest_by = 'date_created'

	name = models.CharField(max_length=30, unique=True) 
	public = models.BooleanField(default=False)
	secret_key = models.CharField(max_length=50) 
	description = models.TextField(blank=True)
	unread_messages = models.IntegerField(null=True, blank=True)
	members = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name='users', blank=True, null=True)
	date_created = models.DateField(("Date"), default=date.today)
	archived = models.BooleanField(default=False, blank=True)
	admin = models.ForeignKey(User)

	def __unicode__(self):
		return u"{0}".format(self.name)

	def get_absolute_url(self):
		return reverse('hubdetail', kwargs={'pk': self.pk})


class Post(models.Model):
	""" Posts that will be inside each Hub. """

	class Meta:
		get_latest_by = 'date_created'

	types = (
		("Image", "Image"),
		("Text", "Text"),
		("URL", "URL")
	)
	type_of = models.CharField(max_length=30, choices=types, default="Text")
	message = models.TextField(max_length=200, blank=True, null=True)
	date_created = models.DateField(('Date'), default=date.today)
	created_by = models.ForeignKey(User, default=None)
	hub = models.ForeignKey(Hub)
	image = models.FileField(blank=True, null=True)
	votes = models.IntegerField(default=0)
	archived = models.BooleanField(default=False, blank=True)

	def __unicode__(self):
		if self.message:
			display = self.message
		else: display = "image from {0}".format(self.created_by)
		return u"{0}: {1}".format(self.type_of, display)


class Comment(models.Model):
	""" Comments that will be under each Post. """

	post = models.ForeignKey(Post)
	comment = models.CharField(max_length=200, blank=False)
	created_by = models.ForeignKey(User, default=None)
	date_created = models.DateField(('Date'), default=date.today)

	def __unicode__(self):
		return u"{0}: {1}".format(self.created_by, self.post)
