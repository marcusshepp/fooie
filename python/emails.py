import random

email = "user@service.com, "

def add_to(email):
    split_email = email.split("@")
    email = split_email
    user = email[0]
    service = email[1]
    email = user + "+" 
    email += str(random.randint(0, 100)) 
    email += "@" + service
    return email
    
emails = [add_to(i) for i in (email*11).split(" ") if len(i.strip()) > 0 ]
print " ".join(emails)
print "\nnumber of emails: {email_length}".format(email_length=len(emails))