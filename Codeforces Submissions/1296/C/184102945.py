t = int(input())
for q in range(t):
    n = int(input())
    s = input().strip()
    l, r = 0, n
    p = (0,0)
    d = {p:1}
    i = 1
    for v in s:
        if v == 'L':
            p = (p[0]-1, p[1])
        elif v == 'R':
            p = (p[0]+1, p[1])
        elif v == 'U':
            p = (p[0], p[1]-1)
        else:
            p = (p[0], p[1]+1)
        if p in d and i - d[p] < r - l:
        
            l, r = d[p], i
        i += 1
        d[p] = i
    if l: print(l, r)
    else: print(-1)
