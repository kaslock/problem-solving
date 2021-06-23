def solution(s):
    answer = 100000
    s_size = len(s)
    
    if s_size < 2:
        return s_size
    
    for n in range(1, s_size // 2 + 1):
        before = ""
        cnt = 0
        
        res = ""
        for i in range(0, s_size + 1):
            if n + n*i > s_size:
                if cnt > 1:
                    res += str(cnt) + before
                else:
                    res += before
                res += s[n*i:]
                break
    
            cur = s[n*i:n+n*i]
            if before == "":
                before = cur
                cnt = 1
            elif before == cur:
                cnt += 1
            else:
                if cnt > 1:
                    res += str(cnt) + before
                else:
                    res += before
                before = cur
                cnt = 1

        if len(res) < answer:
            answer = len(res)
    return answer