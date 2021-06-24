def solution(new_id):
    answer = ''
    
    new_id = new_id.lower()
    
    for s in new_id:
        if s >= 'a' and s <= 'z':
            answer += s
        if s >= '0' and s <= '9':
            answer += s
        if s == '-' or s == '_':
            answer += s
        if s == '.':
            if answer ==  "" or answer[-1] != '.':
                answer += s
        
    if answer == ".":
        answer = ""

    if answer != "" and answer[-1] == ".":
        answer = answer[:-1]

    if answer != "" and answer[0] == ".":
        answer = answer[1:]

    if answer == "":
        answer = "a"

    if len(answer) >= 16:
        answer = answer[:15]
        if answer[-1] == ".":
            answer = answer[:-1]

    if len(answer) == 1:
        answer *= 3
    if len(answer) == 2:
        answer += answer[-1]
        
    return answer