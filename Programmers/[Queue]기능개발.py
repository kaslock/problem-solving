def solution(progresses, speeds):
    answer = []
    last = 0
    psize = len(progresses)
    
    for i in range(psize):
        t = 100 - progresses[i]
        u = t // speeds[i]
        if t % speeds[i] != 0:
            u += 1
        
        if u > last:
            last = u
            answer.append(1)
        else:
            answer[-1] += 1
            
    return answer