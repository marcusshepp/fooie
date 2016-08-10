l = list()
with open("foo.txt", "r") as f:
    print f.readlines()
    for line in f.readlines():
    	l.append(line)
print l
