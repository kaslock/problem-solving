def solution(price, money, count):
    answer = -1
    arr = [i for i in range(1, 2501)]
    
    answer = sum(arr[:count]) * price - money
    
    if answer < 0:
        return 0
    return answer