cnt = [0, 0]

def algo(arr, r_x, r_y, c_x, c_y):
    if r_y == r_x:
        cnt[arr[r_x][c_x]] += 1
        return
    
    t = arr[r_x][c_x]
    for i in range(r_x, r_y + 1):
        for j in range(c_x, c_y + 1):
            if arr[i][j] != t:
                algo(arr, r_x, (r_x + r_y) // 2, c_x, (c_x + c_y) // 2)
                algo(arr, r_x, (r_x + r_y) // 2, (c_x + c_y) // 2 + 1, c_y)
                algo(arr, (r_x + r_y) // 2 + 1, r_y, c_x, (c_x + c_y) // 2)
                algo(arr, (r_x + r_y) // 2 + 1, r_y, (c_x + c_y) // 2 + 1, c_y)
                return
            
    cnt[t] += 1
    

def solution(arr):
    algo(arr, 0, len(arr) - 1, 0, len(arr) - 1)
    return cnt