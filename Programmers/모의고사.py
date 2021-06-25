def solution(answers):
    answer = []
    
    s1 = [1, 2, 3, 4, 5]
    s2 = [2, 1, 2, 3, 2, 4, 2, 5]
    s3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    s_cnt = [0, 0, 0, 0]
    
    for idx, num in enumerate(answers):
        if s1[idx %  5] == num:
            s_cnt[1] += 1
        if s2[idx %  8] == num:
            s_cnt[2] += 1
        if s3[idx % 10] == num:
            s_cnt[3] += 1
        
    answer.append(1)                    # 1번
    
    if s_cnt[1] == s_cnt[2]:            # 2번
        answer.append(2)
    elif s_cnt[1] < s_cnt[2]:
        answer = [2]
    
    if s_cnt[answer[0]] == s_cnt[3]:    # 3번
        answer.append(3)
    elif s_cnt[answer[0]] < s_cnt[3]:
        answer = [3]
    
    return answer