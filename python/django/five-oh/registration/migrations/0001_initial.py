# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import datetime


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='User',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('firstname', models.CharField(max_length=30)),
                ('lastname', models.CharField(max_length=50)),
                ('email', models.EmailField(unique=True, max_length=100)),
                ('username', models.CharField(unique=True, max_length=50)),
                ('password', models.CharField(max_length=100)),
                ('date_of_registration', models.DateField(default=datetime.date.today, null=True, verbose_name=b'Date', blank=True)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
    ]
