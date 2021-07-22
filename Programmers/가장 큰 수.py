from functools import cmp_to_key

def cmp(x, y):
    if x + y > y + x:
        return -1
    else:
        return 1
    
def solution(numbers):
    
    numbers = list(map(str, numbers))
    numbers.sort(key=cmp_to_key(cmp))
    
    if numbers[0][0] == '0':
        return '0'
    return "".join(numbers)