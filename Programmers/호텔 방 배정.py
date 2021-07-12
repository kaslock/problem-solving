from collections import defaultdict
import sys
sys.setrecursionlimit(200000)

uf = defaultdict(int)

def find(x):
    if uf[x] == 0:  uf[x] = x
    if x == uf[x]:  return x
    uf[x] = find(uf[x])
    return uf[x]

def solution(k, room_number):
    answer = []
    
    for room in room_number:
        cur = find(room)
        answer.append(cur)
        uf[cur] = find(cur + 1)
    
    return answer