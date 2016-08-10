# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import datetime


class Migration(migrations.Migration):

    dependencies = [
        ('registration', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Hub',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=30)),
                ('public', models.BooleanField(default=False)),
                ('secret_key', models.CharField(max_length=50)),
                ('description', models.TextField(blank=True)),
                ('unread_messages', models.IntegerField(null=True, blank=True)),
                ('date_created', models.DateField(default=datetime.date.today, verbose_name=b'Date')),
                ('admin', models.ForeignKey(to='registration.User')),
                ('members', models.ManyToManyField(related_name=b'users', null=True, to='registration.User', blank=True)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Post',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('message', models.TextField(max_length=200)),
                ('date_created', models.DateField(default=datetime.date.today, verbose_name=b'Date')),
                ('created_by', models.ForeignKey(default=0, to='registration.User')),
                ('hub', models.ForeignKey(to='hubtubapp.Hub')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
    ]
