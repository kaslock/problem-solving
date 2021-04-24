from collections import defaultdict

def solution(phone_book):
    answer = True
    dd = defaultdict(int)
    
    for pb in phone_book:
        dd[pb] = 1
    
    for pb in phone_book:
        tmp = ""
        for i in range(len(pb) - 1):
            tmp += pb[i]
            if dd[tmp] == 1:
                return False
    return answer