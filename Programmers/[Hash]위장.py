from collections import defaultdict

def solution(clothes):
    answer = 1
    
    dd = defaultdict(int)
    
    for c in clothes:
        dd[c[1]] += 1
    
    for k in dd.keys():
        answer *= (dd[k] + 1)
    return answer - 1