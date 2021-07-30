def solution(n):
    answer = ''
    
    while True:
        if n == 0:
            break
        if n % 3 == 0:
            answer += '4'
            n = n // 3 - 1
        else:
            answer += str(n % 3)
            n = n // 3
    
    return answer[::-1]