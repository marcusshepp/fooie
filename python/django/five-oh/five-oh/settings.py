"""
Django settings for hubtub project.

For more information on this file, see
https://docs.djangoproject.com/en/1.7/topics/settings/

For the full list of settings and their values, see
https://docs.djangoproject.com/en/1.7/ref/settings/
"""

# Build paths inside the project like this: os.path.join(BASE_DIR, ...)
import os

from django.core.urlresolvers import reverse_lazy
BASE_DIR = os.path.dirname(os.path.dirname(__file__))


# Quick-start development settings - unsuitable for production
# See https://docs.djangoproject.com/en/1.7/howto/deployment/checklist/

# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = 'y7y-#rzwk=ch_($ax!4c%fzy@bcr=-4_=o6eo0!^&jkd0@z6qc'

# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = True

TEMPLATE_DEBUG = True

ALLOWED_HOSTS = ['localhost', '127.0.0.1']


# Application definition

INSTALLED_APPS = (
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'hubtubapp',
    'registration',
    'api',
)

MIDDLEWARE_CLASSES = (
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.auth.middleware.SessionAuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
)

#Authentication backends
# AUTHENTICATION_BACKENDS = (
#     'django.contrib.auth.backends.ModelBackend',
# )

ROOT_URLCONF = 'hubtubapp.urls'

WSGI_APPLICATION = 'five-oh.wsgi.application'

AUTH_USER_MODEL = 'registration.User'

# Database
# https://docs.djangoproject.com/en/1.7/ref/settings/#databases

DATABASES = {
    'default': {
    'ENGINE': 'django.db.backends.postgresql_psycopg2',
    'NAME': 'vagrant',
	'USER': 'vagrant',
	'PASSWORD': 'vagrant',
	'HOST': '127.0.0.1',
	'PORT': '',
    }
}

# Internationalization
# https://docs.djangoproject.com/en/1.7/topics/i18n/

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'UTC'

USE_I18N = True

USE_L10N = True

USE_TZ = False


# Static files (CSS, JavaScript, Images)
# https://docs.djangoproject.com/en/1.7/howto/static-files/

STATIC_URL = '/static/'

MEDIA_ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), '../media/'))
    
MEDIA_URL = '/media/'

# Templates
TEMPLATE_DIRS = (
    os.path.normpath(os.path.join(os.path.dirname(__file__), '../templates')),
)

# TEMPLATE_CONTEXT_PROCESSORS = (
# 	"django.contrib.auth.context_processors.auth",
# 	"django.core.context_processors.debug",
# 	"django.core.context_processors.i18n",
# 	"django.core.context_processors.media",
# 	"django.core.context_processors.static",
# 	"django.core.context_processors.tz",
# 	"django.contrib.messages.context_processors.messages",
# )

LOGIN_URL = '/account/login/'
LOGIN_REDIRECT_URL = reverse_lazy("home")
