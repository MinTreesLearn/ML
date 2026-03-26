t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    if a[0] >= 4:
        print(7)
    else:
        res = 0
        if a[2]:
            res += 1
            a[2] -= 1
        if a[1]:
            res += 1
            a[1] -= 1
        if a[0]:
            res += 1
            a[0] -= 1
        if a[1] and a[2]:
            a[1] -= 1
            a[2] -= 1
            res += 1
        if a[0] and a[1]:
            res += 1
            a[0] -= 1
            a[1] -= 1
            
        if a[0] and a[2]:
            a[0] -= 1
            a[2] -= 1
            res += 1
        if a[0] and a[1] and a[2]:
            res += 1
            a[1] -= 1            
            a[1] -= 1
            a[0] -= 1
        print(res)
            