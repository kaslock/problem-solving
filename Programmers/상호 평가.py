import numpy as np

def evaluation(score):
    if score >= 90:
        return 'A'
    elif score >= 80:
        return 'B'
    elif score >= 70:
        return 'C'
    elif score >= 50:
        return 'D'
    else:
        return 'F'

def solution(scores):
    answer = ''
    scores = np.array(scores).T
    
    for i in range(len(scores)):
        if (list(scores[i])).count(scores[i][i]) == 1:
            if scores[i][i] == max(scores[i]) or scores[i][i] == min(scores[i]):       
                answer += evaluation((sum(scores[i]) - scores[i][i]) / (len(scores) - 1))
                continue
        answer += evaluation(sum(scores[i]) / len(scores))
        
    return answer