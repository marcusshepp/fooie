listOfNames = ['red-l','blue-l','green-s','red-s','blue-s']

new_list_of_names = []
for item in listOfNames:
    category = item.split("-")[0]
    new_item = (item,)
    for other_item in listOfNames:
        if other_item.split("-")[0] == category and other_item not in new_list_of_names and other_item != item:
            new_item = (other_item, new_item[0])
    if len(new_item) == 1:
        new_item = (None, new_item[0])
    new_list_of_names.append(new_item)
    
print new_list_of_names