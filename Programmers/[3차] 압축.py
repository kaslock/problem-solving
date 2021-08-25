from collections import defaultdict

def solution(msg):
    answer = []
    dictionary = defaultdict(int)
    p = 1
    
    for x in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        dictionary[x] = p
        p += 1
    
    t = 0
    while True:
        if t >= len(msg):   break
        for i in range(1, 1000):
            if dictionary[msg[t:t + i]] == 0:
                answer.append(dictionary[msg[t:t + i - 1]])
                dictionary[msg[t:t + i]] = p
                p += 1
                t = t + i - 1
                break
            if t + i == len(msg):
                answer.append(dictionary[msg[t:t + i]])
                t = t + i
                break
    
    return answer