def solution(n, t, m, p):
    answer = ''
    num = "0123456789ABCDEF"
    cnt = 0
    total = ""
    
    for i in range(200000):
        if cnt > t * m + 1: break
        tmp = ""
        if i == 0:  tmp += "0"
        while i > 0:
            tmp += num[i % n]
            i //= n
            cnt += 1
        total += tmp[::-1]
    
    for i in range(len(total)):
        if i % m + 1 == p:
            answer += total[i]
        if len(answer) == t:
            break
    
    return answer