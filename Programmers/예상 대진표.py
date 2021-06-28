def solution(n,a,b):
    answer = 1
    
    if a > b:
        tmp = a
        a = b
        b = tmp

    for n in range(1, 21):    
        if a <= 2**n and b <= 2**n:
            t = 2**n
            answer = n
            break
    
    l = 0
    r = t

    while True:
        m = (l + r) / 2
        if a <= m and b > m:
            break
        if a <= m and b <= m:
            r = m
        if a > m and b > m:
            l = m
        answer -= 1
    
    return answer