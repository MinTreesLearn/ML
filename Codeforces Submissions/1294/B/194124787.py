for _ in range(int(input())):
    a= [(0, 0)]
    n= int(input())
    for i in range(n):
        x, y= map(int, input().split())
        a.append((x, y))
    a.sort()
    s= str()
    for k in range(1, n+1):
        if a[k][0] < a[k-1][0] or a[k][1] < a[k-1][1]:
            print('NO')
            break
        else:
            p= a[k][0]- a[k-1][0]
            q= a[k][1]- a[k-1][1]
            s += (p*'R')+ (q*'U')
    else:
        print('YES')
        print(s)