def solution(number, k):
    answer = ''
    ans_size = len(number) - k
    t = -1
    for i in range(ans_size):
        t += 1
        if k > 0:
            idx = 0
            max_val = -1
            for j in range(t, t + k + 1):
                if int(number[j]) > max_val:
                    idx = j
                    max_val = int(number[j])
                    if max_val == 9:
                        break
            k -= (idx - t)
            t = idx
        
        answer += number[t]
    
    return answer