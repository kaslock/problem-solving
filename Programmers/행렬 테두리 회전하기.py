def solution(rows, columns, queries):
    answer = []
    
    matrix = [[0]*(columns + 1) for _ in range(rows + 1)]
    cnt = 1
    for i in range(1, rows + 1):
        for j in range(1, columns + 1):
            matrix[i][j] = cnt
            cnt += 1
    
    for query in queries:
        x1, y1, x2, y2 = query
        min_val = int(1e9)
        
        tmp = matrix[x1][y1]
        i = x1
        for j in range(y1 + 1, y2 + 1):
            min_val = min(min_val, matrix[i][j])
            matrix[i][j], tmp = tmp, matrix[i][j]   # swap
        
        j = y2
        for i in range(x1 + 1, x2 + 1):
            min_val = min(min_val, matrix[i][j])
            matrix[i][j], tmp = tmp, matrix[i][j]   # swap
        
        i = x2
        for j in range(y2 - 1, y1 - 1, -1):
            min_val = min(min_val, matrix[i][j])
            matrix[i][j], tmp = tmp, matrix[i][j]   # swap

        j = y1
        for i in range(x2 - 1, x1 - 1, -1):
            min_val = min(min_val, matrix[i][j])
            matrix[i][j], tmp = tmp, matrix[i][j]   # swap

        answer.append(min_val)
        
    return answer