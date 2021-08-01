def solution(s):
    
    arr = s.split(' ')
    arr = list(map(int, arr))
    answer = str(min(arr)) + ' ' + str(max(arr))
    
    return answer