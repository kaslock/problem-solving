from collections import defaultdict
from bisect import bisect_left

def solution(info, query):
    answer = []
    scores = defaultdict(list)
    
    for cmd in info:
        c = cmd.split(' ')
        scores[c[0] + c[1] + c[2] + c[3]].append(int(c[4]))
        scores[c[0] + c[1] + c[2] + '-'].append(int(c[4]))
        scores[c[0] + c[1] + '-' + c[3]].append(int(c[4]))
        scores[c[0] + '-' + c[2] + c[3]].append(int(c[4]))
        scores['-' + c[1] + c[2] + c[3]].append(int(c[4]))
        scores[c[0] + c[1] + '-' + '-'].append(int(c[4]))
        scores[c[0] + '-' + c[2] + '-'].append(int(c[4]))
        scores['-' + c[1] + c[2] + '-'].append(int(c[4]))
        scores[c[0] + '-' + '-' + c[3]].append(int(c[4]))
        scores['-' + c[1] + '-' + c[3]].append(int(c[4]))
        scores['-' + '-' + c[2] + c[3]].append(int(c[4]))
        scores[c[0] + '-' + '-' + '-'].append(int(c[4]))
        scores['-' + c[1] + '-' + '-'].append(int(c[4]))
        scores['-' + '-' + c[2] + '-'].append(int(c[4]))
        scores['-' + '-' + '-' + c[3]].append(int(c[4]))
        scores['----'].append(int(c[4]))
        
    for cmd in scores:
        scores[cmd].sort()
        
    for cmd in query:
        cmd = cmd.replace('and ', '')
        c = cmd.split(' ')
        x = bisect_left(scores[c[0] + c[1] + c[2] + c[3]], int(c[4]))
        answer.append(len(scores[c[0] + c[1] + c[2] + c[3]]) - x)
    
    return answer