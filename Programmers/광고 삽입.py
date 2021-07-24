def solution(play_time, adv_time, logs):
    answer = ''
    
    hh, mm, ss = play_time.split(":")
    p_time = int(hh)*3600 + int(mm)*60 + int(ss) + 1
    p_arr = [0] * (p_time)
    b_arr = [0] * (p_time)
    
    hh, mm, ss = adv_time.split(":")
    a_time = int(hh)*3600 + int(mm)*60 + int(ss)
    
    for log in logs:
        l1, l2 = log.split("-")
        hh, mm, ss = l1.split(":")
        p_arr[int(hh)*3600 + int(mm)*60 + int(ss)] += 1
        hh, mm, ss = l2.split(":")
        p_arr[int(hh)*3600 + int(mm)*60 + int(ss)] -= 1
    
    res = 0
    ans = 0
    amount = 0
    cur = 0
    
    for i in range(p_time):
        cur += p_arr[i]
        b_arr[i] = cur
        amount += cur
        if i == a_time:
            if amount > res:
                res = amount
                ans = 0
    
        if i > a_time:
            amount -= b_arr[i - a_time]

            if amount > res:
                res = amount
                ans = i - a_time + 1
    
    h = ans // 3600
    if h < 10:
        h = "0" + str(h)
    else:
        h = str(h)
    ans %= 3600
    m = ans // 60
    if m < 10:
        m = "0" + str(m)
    else:
        m = str(m)
    ans %= 60
    s = ans
    if s < 10:
        s = "0" + str(s)
    else:
        s = str(s)
    
    answer = h + ":" + m + ":" + s
    return answer