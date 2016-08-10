from datetime import datetime

from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager


class UserObjectManager(BaseUserManager):
	""" Class used to manage User objects. """

	def create_user(self, username, email, password):
		user = self.model(
			username=username, 
			email=email,
			password=password
			)
		user.set_password(password)
		user.save()
		return user

	def create_superuser(self, username, email, password):
		user = self.create_user(
			username=username, 
			email=email,
			password=password
			)
		user.is_admin = True
		user.is_superuser = True
		user.is_staff = True
		user.save()
		return user


class User(AbstractBaseUser):
	""" Generic User objects. """

	firstname = models.CharField(max_length=30, unique=False)
	lastname = models.CharField(max_length=50, unique=False)
	email = models.EmailField(max_length=100, unique=True)
	username = models.CharField(max_length=50, unique=True)
	date_of_registration = models.DateTimeField(('date joined'), default=datetime.now)
	date_joined = models.DateTimeField(('date joined'), default=datetime.now)
	is_active = models.BooleanField(default=True)
	is_admin = models.BooleanField(default=False)
	is_staff = models.BooleanField(default=False)
	is_superuser = models.BooleanField(default=False)

	USERNAME_FIELD = 'username'
	REQUIRED_FIELDS = ['email']
	objects = UserObjectManager()

	def __unicode__(self):
		return u"{}".format(self.username)

	def get_short_name(self):
		return "%s" % self.firstname

	def get_username(self):
		return "%s" % self.username

	def has_perm(self, perm):
		return True

	def has_module_perms(self, module):
		return True
