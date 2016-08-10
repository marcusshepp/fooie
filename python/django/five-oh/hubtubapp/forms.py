from django import forms
from django.forms import ModelForm
from django.forms.widgets import PasswordInput

from .models import Hub, Post


class HubForm(ModelForm):

	secret_key = forms.CharField(required=False, widget=PasswordInput)

	class Meta:

		model = Hub
		fields = ['name', 'public', 'secret_key', 'description']


class PostForm(ModelForm):

	class Meta:

		model = Post
		fields = ['message']
		labels = {
			'message': 'Contribute to Conversation'
		}
		widgets = {
            'message': forms.TextInput(
                attrs={'id': 'post-text', 'required': True, 'placeholder': 'Say something...'}
            ),
        }

class SecretKey(forms.Form):

	secret_key = forms.CharField(label='Secret Key', widget=PasswordInput())