from collections import defaultdict

def solution(record):
    answer = []
    
    user = defaultdict()    # key: userID, value: Nickname
    vis = []    # 방문 기록
    for re in record:
        cmd = re.split(" ")
        if cmd[0] == "Enter":
            user[cmd[1]] = cmd[2]
            vis.append([cmd[1], 1]) # Enter은 1
        if cmd[0] == "Leave":
            vis.append([cmd[1], 0]) # Leave는 0
        if cmd[0] == "Change":
            user[cmd[1]] = cmd[2]
    
    # 방문 기록 문자열로 변환
    for v in vis:
        if v[1] == 1:
            answer.append(user[v[0]] + "님이 들어왔습니다.")
        else:
            answer.append(user[v[0]] + "님이 나갔습니다.")
            
    return answer