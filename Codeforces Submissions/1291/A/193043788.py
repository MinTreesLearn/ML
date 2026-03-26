# LUOGU_RID: 101844775
for _ in range(int(input())):
    n = int(input())
    s = input()
    a = []
    for c in s:
        if int(c) & 1:
            a += int(c),
    
    if len(a) < 2:
        print(-1)
    else:
        print(a[0], a[1], sep='')