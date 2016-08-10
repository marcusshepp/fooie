from django.contrib import admin

from .models import Hub, Post

@admin.register(Hub)
class HubAdmin(admin.ModelAdmin):
    date_hierarchy = 'date_created'
    list_display = ('name', 'description', 'date_created')


@admin.register(Post)
class HubAdmin(admin.ModelAdmin):
    date_hierarchy = 'date_created'