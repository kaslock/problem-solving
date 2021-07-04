def solution(n, words):
    used = []
    for i, w in enumerate(words):
        if i == 0:  pass
        elif w[0] != used[-1][-1] or w in used:
            return [i % n + 1, i // n + 1]
        used.append(w)
    
    return [0, 0]