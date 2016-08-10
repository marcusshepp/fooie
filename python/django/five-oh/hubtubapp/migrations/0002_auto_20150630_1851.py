# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import datetime
from django.conf import settings


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('hubtubapp', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Comment',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('comment', models.CharField(max_length=200)),
                ('date_created', models.DateField(default=datetime.date.today, verbose_name=b'Date')),
                ('created_by', models.ForeignKey(default=None, to=settings.AUTH_USER_MODEL)),
                ('post', models.ForeignKey(to='hubtubapp.Post')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.AlterModelOptions(
            name='hub',
            options={'get_latest_by': 'date_created'},
        ),
        migrations.AlterModelOptions(
            name='post',
            options={'get_latest_by': 'date_created'},
        ),
        migrations.AddField(
            model_name='hub',
            name='archived',
            field=models.BooleanField(default=False),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='post',
            name='archived',
            field=models.BooleanField(default=False),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='post',
            name='image',
            field=models.FileField(null=True, upload_to=b'', blank=True),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='post',
            name='type_of',
            field=models.CharField(default=b'Text', max_length=30, choices=[(b'Image', b'Image'), (b'Text', b'Text'), (b'URL', b'URL')]),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='post',
            name='votes',
            field=models.IntegerField(default=0),
            preserve_default=True,
        ),
        migrations.AlterField(
            model_name='post',
            name='created_by',
            field=models.ForeignKey(default=None, to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='post',
            name='message',
            field=models.TextField(max_length=200, null=True, blank=True),
        ),
    ]
