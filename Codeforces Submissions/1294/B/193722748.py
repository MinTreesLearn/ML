for _ in range(int(input())) : 
    n = int(input()); l = [ ]
    for i in range(n) : l.append(tuple(map(int,input().split())))
    l.sort(); x = y = 0; res = 'YES'; s = '' 
    for i in l : 
        x1, y1 = i[0], i[1]
        if x1 < x or y1 < y : res = 'NO'; break 
        s += (x1 - x) * 'R' + (y1 - y) * 'U'; x = x1; y = y1
    else : print(res); print(s); continue 
    print(res)