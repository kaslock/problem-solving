def solution(game_board, table):
    answer = 0
    N = len(table)
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    
    # block number
    block_size = []
    vis = [[0] * N for _ in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(N):
            if vis[i][j] == 1:  continue
            if table[i][j] == 1:
                cnt += 1
                q = []
                q.append([i, j])
                b_size = 0
                vis[i][j] = 1
                while q != []:
                    cur = q.pop(0)
                    b_size += 1
                    table[cur[0]][cur[1]] = cnt
                    for k in range(4):
                        if cur[0] + dx[k] < 0 or cur[0] + dx[k] >= N:
                            continue
                        if cur[1] + dy[k] < 0 or cur[1] + dy[k] >= N:
                            continue
                        if vis[cur[0] + dx[k]][cur[1] + dy[k]] == 1:
                            continue
                        if table[cur[0] + dx[k]][cur[1] + dy[k]] == 1:
                            vis[cur[0] + dx[k]][cur[1] + dy[k]] = 1
                            q.append([cur[0] + dx[k], cur[1] + dy[k]])       
                block_size.append(b_size)
    
    # game board
    boards = []
    vis = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if vis[i][j] == 1:  continue
            if game_board[i][j] == 0:
                board = [[0] * 10 for _ in range(10)]
                q = []
                q.append([i, j])
                vis[i][j] = 1
                while q != []:
                    cur = q.pop(0)
                    board[cur[0] - i][cur[1] - j + 5] = 1
                    for k in range(4):
                        if cur[0] + dx[k] < 0 or cur[0] + dx[k] >= N:
                            continue
                        if cur[1] + dy[k] < 0 or cur[1] + dy[k] >= N:
                            continue
                        if vis[cur[0] + dx[k]][cur[1] + dy[k]] == 1:
                            continue
                        if game_board[cur[0] + dx[k]][cur[1] + dy[k]] == 0:
                            vis[cur[0] + dx[k]][cur[1] + dy[k]] = 1
                            q.append([cur[0] + dx[k], cur[1] + dy[k]])

                boards.append(board)
    
    # blocks init
    blocks = [[] for _ in range(4)]
    for i in range(4):
        for j in range(cnt):
            block = [[0] * 10 for _ in range(10)]
            blocks[i].append(block)
    
    # get block in rotated table
    for x in range(4):
        rotated_table = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(N):
                rotated_table[j][N - 1 - i] = table[i][j]
        
        table = rotated_table
        
        vis = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(N):
                if vis[i][j] == 1:  continue
                if table[i][j] > 0:
                    q = []
                    q.append([i, j])
                    vis[i][j] = 1
                    while q != []:
                        cur = q.pop(0)
                        blocks[x][table[i][j] - 1][cur[0] - i][cur[1] - j + 5] = 1
                        for k in range(4):
                            if cur[0] + dx[k] < 0 or cur[0] + dx[k] >= N:
                                continue
                            if cur[1] + dy[k] < 0 or cur[1] + dy[k] >= N:
                                continue
                            if vis[cur[0] + dx[k]][cur[1] + dy[k]] == 1:
                                continue
                            if table[cur[0] + dx[k]][cur[1] + dy[k]] > 0:
                                vis[cur[0] + dx[k]][cur[1] + dy[k]] = 1
                                q.append([cur[0] + dx[k], cur[1] + dy[k]])
            
    used = [0] * cnt
    for board in boards:
        for i in range(cnt):
            if used[i] == 1:    continue
            if board == blocks[0][i] or board == blocks[1][i] or \
            board == blocks[2][i] or board == blocks[3][i]:
                answer += block_size[i]
                used[i] = 1
                break
            
    
    return answer