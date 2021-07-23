import random

ORDERID = '[[ORDERID]]'
TRAILERSERIAL = '[[TRAILERSERIAL]]'
HULLID = '[[HULLID]]'

def replace(line, str_found):
    generated_number = random.randint(100000, 999999)
    return str(line).replace(str_found, str(generated_number))


with open("TestInvoice-Axis.xml", "r") as base_file:
    new_file = open("generated-tests/test.xml", "w")
    for line in base_file:
        stripped_line = line.strip()
        new_line = ''
        if ORDERID in stripped_line:
            print('order id found -- replacing')
            new_line = replace(stripped_line, ORDERID)
        elif TRAILERSERIAL in stripped_line:
            print('trailer serial found -- replacing')
            new_line = replace(stripped_line, TRAILERSERIAL)
        elif HULLID in stripped_line:
            print('hull id found -- replacing')
            new_line = replace(stripped_line, HULLID)
        else:
            new_line = stripped_line
        new_file.write(new_line + '\n')
    new_file.close()