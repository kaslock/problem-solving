from collections import defaultdict

def solution(skill, skill_trees):
    answer = len(skill_trees)
    sk = defaultdict(int)
    lv = 1
    
    for s in skill:
        sk[s] = lv
        lv += 1
        
    for skill_tree in skill_trees:
        cur = 0
        for s in skill_tree:
            if sk[s] > 0:
                if sk[s] != cur + 1:
                    answer -= 1
                    break
                cur = sk[s]

    return answer