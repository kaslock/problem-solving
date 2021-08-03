import re
from collections import defaultdict

def calc_time(start_time, end_time):
    h1, m1 = start_time.split(":")
    h2, m2 = end_time.split(":")
    
    start_time = int(h1) * 60 + int(m1)
    end_time = int(h2) * 60 + int(m2)
    
    return end_time - start_time

def solution(m, musicinfos): 
    res = []
    music_len = defaultdict(int)
    
    p = re.compile('[A-G]#?')
    m = p.findall(m)
    
    for i in range(len(m)):
        if m[i] == 'A#':
            m[i] = 'a'
        if m[i] == 'C#':
            m[i] = 'c'
        if m[i] == 'D#':
            m[i] = 'd'
        if m[i] == 'F#':
            m[i] = 'f'
        if m[i] == 'G#':
            m[i] = 'g'
    m = "".join(m)
    
    for musicinfo in musicinfos:
        start_time, end_time, title, music = musicinfo.split(",")
        play_time = calc_time(start_time, end_time)
        
        music = p.findall(music)
        music_len[title] = play_time

        if play_time <= len(music):
            music = music[:play_time]
        else:
            a = play_time // len(music)
            b = play_time % len(music)
            
            music = a * music + music[:b]
        
        for i in range(len(music)):
            if music[i] == 'A#':
                music[i] = 'a'
            if music[i] == 'C#':
                music[i] = 'c'
            if music[i] == 'D#':
                music[i] = 'd'
            if music[i] == 'F#':
                music[i] = 'f'
            if music[i] == 'G#':
                music[i] = 'g'
        
        music = "".join(music)
        if m in music:
            res.append(title)
    
    if res == []:
        return "(None)"
    
    answer = ''
    max_len = 0
    for r in res:
        if max_len < music_len[r]:
            max_len = music_len[r]
            answer = r
    
    return answer