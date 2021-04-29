def solution(bridge_length, weight, truck_weights):
    answer = 0
    
    f = []
    q = []
    qw = 0
    
    for i in range(bridge_length):
        q.append(0)
        
    while True:
        answer += 1
        tmp = q.pop(0)
        qw -= tmp
        if tmp > 0: f.append(tmp)
        if not truck_weights:   break
        if qw + truck_weights[0] > weight:
            q.append(0)
        else:
            tw = truck_weights.pop(0)
            qw += tw
            q.append(tw)
        
        
    if q != []:
        for x in q:
            if x > 0:
                f.append(x)
            answer += 1
            
    return answer