def solution(priorities, location):
    cnt = 0
    psize = len(priorities)
    vis = [0 for _ in range(psize)]
    
    while True:
        cur = cnt % psize
        if vis[location] == 1:  return sum(vis)            
        if priorities[cur] == max(priorities):
            priorities[cur] = 0
            vis[cur] = 1
        
        cnt += 1