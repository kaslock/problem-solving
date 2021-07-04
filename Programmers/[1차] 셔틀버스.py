def solution(n, t, m, timetable):
    bus_schedule = ["09:00"]
    timetable.sort()
    
    for i in range(n - 1):
        HH, MM = bus_schedule[-1].split(":")
        HH = int(HH)
        MM = int(MM) + t
        
        if MM >= 60:
            HH += 1
            MM -= 60
        if HH < 10:
            HH = "0" + str(HH)
        if MM < 10:
            MM = "0" + str(MM)
            
        bus_schedule.append(str(HH) + ":" + str(MM))
    
    cur = 0
    for idx, bus_time in enumerate(bus_schedule):
        if cur == len(timetable):
            return bus_schedule[-1]
        if idx == n - 1:    # 마지막 버스
            last_bus = [x for x in timetable[cur:] if x <= bus_schedule[-1]]
            if len(last_bus) < m:
                return bus_schedule[-1]
            else:
                HH, MM = last_bus[m - 1].split(":")
                HH = int(HH)
                MM = int(MM) - 1
                
                if MM < 0:
                    HH -= 1
                    MM = 59
                if HH < 10:
                    HH = "0" + str(HH)
                if MM < 10:
                    MM = "0" + str(MM)
                
                return str(HH) + ":" + str(MM)
            
        for i in range(m):
            if cur == len(timetable) or timetable[cur] > bus_time:
                break
            cur += 1
    
    return bus_schedule[-1]