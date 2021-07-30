def solution(n):
    answer = 0
    
    cur = 0
    f = 0
    for i in range(n + 2):
        while cur > n:
            if f > i:
                return answer
            cur -= f
            f += 1
        if cur == n:
            answer += 1    
        cur += i
        
    return answer