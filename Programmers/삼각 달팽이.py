def solution(n):
    answer = []
    
    arr = [[] for _ in range(n + 1)]
    
    if n == 1:
        return [1]
    
    num = 1
    for k in range(n // 2):
        if 1 + 2 * k > n - k:  break
        for i in range(1 + 2 * k, n - k + 1):
            arr[i].insert(k, num)
            num += 1
        while len(arr[n - k]) != n - k:
            if k == 0:
                arr[n - k].append(num)
            else:
                arr[n - k].insert(k*(-1), num)
            num += 1
        for i in range(n - k - 1, 1 + 2 * k, -1):
            if k == 0:
                arr[i].append(num)
            else:
                arr[i].insert(k*(-1), num)
            num += 1
    
    for i in range(1, n + 1):
        answer += arr[i]

    return answer