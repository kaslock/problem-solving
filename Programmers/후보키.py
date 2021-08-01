from collections import defaultdict

arr = [[] for _ in range(9)]

def subset(d, col_size, vis, relation):
    if d == col_size:
        candidate = defaultdict(int)
        for row in relation:
            key = ''
            for i in range(col_size):
                if vis[i] > 0:
                    key += row[i] + ' '
            if candidate[key] != 0:
                return
            candidate[key] = 1
        
        tmp = ''
        for i in range(col_size):
            if vis[i] > 0:
                tmp += str(i)
        arr[len(tmp)].append(tmp)
        
        return
    
    if vis[d] > 0:  return
    
    vis[d] = 1
    subset(d + 1, col_size, vis, relation)
    vis[d] = 0
    subset(d + 1, col_size, vis, relation)
    
    return

def check(x, res):
    if res == []:
        return True
    
    for r in res:
        cnt = 0
        for t in range(len(r)):
            if r[t] in x:
                cnt += 1
        if cnt == len(r):
            return False
    
    return True

def solution(relation):
    vis = [0] * len(relation[0])
    subset(0, len(relation[0]), vis, relation)
    
    res = []
    for a in arr:
        for i in range(len(a)):
            if check(a[i], res):
                res.append(a[i])
    
    return len(res)