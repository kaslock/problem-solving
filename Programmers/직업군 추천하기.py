from collections import defaultdict

def solution(table, languages, preference):
    answer = ''
    
    score_board = defaultdict()
    
    for ta in table:
        t = ta.split(' ')
        score_board[t[0]] = defaultdict(int)
        for i in range(5):
            score_board[t[0]][t[i + 1]] = 5 - i
    
    max_val = -1
    for job in score_board:
        cur = 0
        for i in range(len(languages)):
            cur += score_board[job][languages[i]] * preference[i]
        if cur >= max_val:
            if cur == max_val and job > answer:
                continue
            max_val = cur
            answer = job
            
    return answer