from django.shortcuts import render
from django.http import HttpResponse

def foo(request, *args, **kwargs):
    print kwargs
    return HttpResponse("foo")
