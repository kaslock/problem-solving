def algo(place):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    
    for i in range(5):
        for j in range(5):
            if place[i][j] == 'P':
                for k in range(4):
                    if i+dx[k] < 0 or i+dx[k] >= 5: continue
                    if j+dy[k] < 0 or j+dy[k] >= 5: continue
                    if place[i+dx[k]][j+dy[k]] == 'P':
                        return 0
                    if place[i+dx[k]][j+dy[k]] == 'O':
                        x = i+dx[k]
                        y = j+dy[k]
                        for t in range(4):
                            if x+dx[t] == i and y+dy[t] == j: continue
                            if x+dx[t] < 0 or x+dx[t] >= 5: continue
                            if y+dy[t] < 0 or y+dy[t] >= 5: continue
                            if place[x+dx[t]][y+dy[t]] == 'P':
                                return 0
    return 1

def solution(places):
    answer = []
    
    for place in places:
        answer.append(algo(place))
        
    return answer