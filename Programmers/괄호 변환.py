def algo(w):
    u = ''
    v = ''
    if len(w) < 1:
        return ''
    l = 0
    r = 0
    cur = -1
    for i in range(len(w)):
        if w[i] == '(':
            l += 1
        if w[i] == ')':
            r += 1
        if l == r:
            cur = i
            break
    
    u = w[:cur + 1]
    if cur + 1 < len(w):
        v = w[cur + 1:]
    
    if u[0] == '(':
        return u + algo(v)
    else:
        res = ''
        for x in u:
            if x == '(':
                res += ')'
            else:
                res += '('
        return '(' + algo(v) + ')' + res[1:-1]
        
def solution(p):
    answer = algo(p)
    return answer