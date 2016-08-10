from django.contrib import admin

from .models import User


@admin.register(User)
class HubAdmin(admin.ModelAdmin):
    date_hierarchy = 'date_of_registration'