def valid(s):
    j = len(s)
    for i in range(j // 2):
        if s[i] != s[j - 1 - i]:
            return False
    return True

def solution(s):
    answer = 0

    for i in range(1, len(s) + 1):
        for j in range(len(s)):
            if j + i > len(s):  break
            if valid(s[j:j + i]):
                answer = i
                break

    return answer