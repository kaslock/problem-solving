def solution(prices):
    answer = []
    psize = len(prices)
    
    for i in range(psize - 1):
        cnt = 0
        for j in range(i+1, psize):
            cnt += 1
            if prices[i] > prices[j]:
                break
        answer.append(cnt)
    answer.append(0)
    return answer