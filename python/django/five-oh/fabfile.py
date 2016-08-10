from fabric.api import *

def hello(name="world"):
	print "Hello there, %s" % name

def auto_push():
	local("git ci -am 'auto push from fab file'")
	local("git push origin master")
	return "Finished pushing"

def pull_origin():
	local("git pull origin master")

def run():
	local("python manage.py runserver")
	if results.failed and not confirm("I failed you master..."):
		abort("Aborting at master request")
	return "Server running"

def mkmi():
	local("python manage.py makemigrations")

def mi():
	local("python manage.py migrate")

def sdb():
	local("python manage.py syncdb")
