from collections import defaultdict

max_val = [0] * 30
menu_set = defaultdict(int)

def combi(order, vis, cur, before, n, course):
    if n in course:
        tmp = "".join(cur)
        menu_set[tmp] += 1
        if menu_set[tmp] > max_val[n]:
            max_val[n] = menu_set[tmp]
    if n == 10: return
    
    for i in range(before, len(order)):
        if vis[i] == 1: continue
        vis[i] = 1
        cur.append(order[i])
        combi(order, vis, cur, i, n + 1, course)
        cur.pop()
        vis[i] = 0
    
def solution(orders, course):
    answer = []
    N = len(orders)
    
    for i in range(N):
        tmp = list(orders[i])
        tmp.sort()
        orders[i] = "".join(tmp)

    for order in orders:
        combi(list(order), [0]*30, [], 0, 0, course)
        
    for m in menu_set:
        if max_val[len(m)] == menu_set[m] and menu_set[m] >= 2:
            answer.append(m)
    answer.sort()
    
    return answer