from django import forms
from django.forms import ModelForm, CharField
from django.forms.widgets import PasswordInput
from django.contrib.auth import login, authenticate

from .models import User


class UserRegistrationForm(ModelForm):

	password_two = forms.CharField(
		max_length=100,
		label='Verify Password',
		widget=forms.PasswordInput
		)

	class Meta:

		model = User
		fields = ('firstname', 'lastname', 'email', 'username', 'password', 'password_two')
		widgets = {
			'password': forms.PasswordInput(),
			'email': forms.EmailInput(),
		}

	def clean_password_two(self):
		one = self.cleaned_data['password']
		two = self.cleaned_data['password_two']
		if one != two:
			raise forms.ValidationError("Password fields must match.")

	def save(self, commit=True):
		user = super(UserRegistrationForm, self).save(commit=False)
		user.set_password(self.cleaned_data["password"])
		if commit:
			user.save()
		return user


class UserLoginForm(forms.Form):

	username = forms.CharField(label='Username')
	password = forms.CharField(label="Password", widget=PasswordInput)

