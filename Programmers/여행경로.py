from collections import defaultdict

ticket_dict = defaultdict(list)
city_count = 0
res = []
answer = []
finish = 0

def dfs(n, cur):
    global answer
    
    if n == 1:
        if answer == []:
            answer = res.copy()
        return
    
    for i, x in enumerate(ticket_dict[cur]):
        tmp = ticket_dict[cur][i]
        del ticket_dict[cur][i]
        res.append(x)
        dfs(n - 1, x)
        res.pop()
        ticket_dict[cur].insert(i, tmp)
        
def solution(tickets):
    city_count = len(tickets) + 1
    
    for ticket in tickets:
        ticket_dict[ticket[0]].append(ticket[1])
    
    for city in ticket_dict:
        ticket_dict[city].sort()
    
    res.append("ICN")
    dfs(city_count, "ICN")
    
    return answer