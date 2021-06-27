def solution(citations):
    answer = 0
    
    for i in range(len(citations) + 1):
        cnt = 0
        for j in citations:
            if j >= i:
                cnt += 1
            if cnt == i:
                answer = i
                break
                
    return answer