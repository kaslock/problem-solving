from collections import defaultdict

def solution(genres, plays):
    answer = []
    
    genre_dict = defaultdict(list)
    play_count = defaultdict(int)
    
    play_size = len(genres)
    
    for i in range(play_size):
        genre_dict[genres[i]].append((plays[i], i*(-1)))
        play_count[genres[i]] += plays[i]
    
    sorted_genre = sorted(play_count.items(), reverse=True, key=lambda item:item[1])
    
    for gen in sorted_genre:
        sorted_arr = sorted(genre_dict[gen[0]], reverse=True)
        answer.append(sorted_arr[0][1]*(-1))
        if len(sorted_arr) >= 2:
            answer.append(sorted_arr[1][1]*(-1))
        
    return answer