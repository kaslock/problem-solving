def cmp(x, y):
    if x >= y:   return True
    
    if y - x < 1000:
        return True

    return False

def solution(lines):
    answer = 0
    in_arr = []
    out_arr = []
    
    for line in lines:
        _, time, runtime = line.split(" ");
        runtime = runtime.replace("s", "")
        hh, mm, ss = time.split(":")
        out_time = int((int(hh)*3600 + int(mm)*60 + round(float(ss), 3))*1000)
        out_arr.append(out_time)
        in_time = out_time - int((round(float(runtime), 3))*1000) + 1
        in_arr.append(in_time)
    
    in_arr.sort()
    out_arr.sort()
    
    print(in_arr, out_arr)
    
    f = 0
    cur = 0
    
    for i in range(len(in_arr)):
        cur += 1
        
        while cmp(out_arr[f], in_arr[i]) == False:
            if f == i:
                break
            cur -= 1
            f += 1
        
        if cur > answer:
            answer = cur
            
    return answer