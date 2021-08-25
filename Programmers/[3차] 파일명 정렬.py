import re
from functools import cmp_to_key

def cmp(x, y):
    if x[0] > y[0]:
        return 1
    elif x[0] == y[0]:
        if x[1] > y[1]:
            return 1
        elif x[1] < y[1]:
            return -1
        else:
            return 0
    else:
        return -1

def solution(files):
    answer = []
    
    reg1 = re.compile('[a-zA-Z-. ]+')
    reg2 = re.compile('[0-9]+')
    
    new_files = []
    
    for file in files:
        head    = reg1.search(file).group()
        number  = reg2.search(file).group()
        tail = file[len(head) + len(number):]
        new_files.append([head.lower(), int(number), tail, file])
    
    sorted_files = sorted(new_files, key=cmp_to_key(cmp))
    
    for file in sorted_files:
        answer.append(file[3])
    
    return answer