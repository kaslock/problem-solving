def solution(begin, target, words):
    if target not in words:
        return 0
    
    q = []
    q.append([begin, 0])
    if begin in words:
        words.remove(begin)
    
    while q != []:
        cur, cnt = q.pop(0)
        
        if cur == target:
            return cnt
        
        cur = list(cur)
        for word in words:
            for i, w in enumerate(word):
                tmp = cur[i]
                cur[i] = w
                new_word = "".join(cur)
                cur[i] = tmp
                if new_word == word:
                    words.remove(new_word)
                    q.append([new_word, cnt + 1])
                    break

    return 0