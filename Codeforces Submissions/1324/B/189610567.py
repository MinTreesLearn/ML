t = int(input())
while t>0:
    n = int(input())
    l = list(map(int, input().split()))
    for i in range(n - 2):
        if l[i] in l[i + 2:]:
            print('YES')
            break
    else:
        print('NO')
    t-=1
