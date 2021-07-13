fact = [0] * 21

def factorial(x):
    if x < 2:
        return 1
    fact[x] = x * factorial(x - 1);
    return fact[x]

def solution(n, k):
    answer = []
    arr = [i for i in range(1, n + 1)]
    
    fact[1] = 1
    factorial(20)
    
    for i in range(n, 0, -1):
        cur = fact[i] / i
        for j in range(i):
            if k <= cur * (j + 1):
                k -= cur * j
                answer.append(arr[j])
                del arr[j]
                break
                
    return answer