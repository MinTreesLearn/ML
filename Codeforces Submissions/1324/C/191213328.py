test_cases = int(input())


for t in range(test_cases):
    s=[]
    ws=list(input())
    for w in ws:
        if len(s) == 0 or s[-1][0] != w:
            s.append((w, 1))
        else:
            s[-1] = (s[-1][0], s[-1][1]+1)
    s.reverse()
    d=0
    p=0
    max_l = 0
    while s:
        c, n = s.pop()
        if c == 'L':
            max_l = max(max_l, n)
        

    print(max_l+1)