from collections import defaultdict

def solution(participant, completion):
    answer = ''

    dd = defaultdict(int)
    
    for c in completion:
        dd[c] += 1
        
    for p in participant:
        if dd[p] > 0:
            dd[p] -= 1
        else:
            return p
            
    return answer