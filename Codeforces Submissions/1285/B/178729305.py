n = int(input())
for t in range(n):
    m = int(input())
    a = list(map(int, input().split()))
    ans1 = sum(a)
    ans2 = 0
    dlina = 0
    maxim = 0
    for i in range(m):
        if dlina != m - 1:
            ans2 += a[i]
            if ans2 > 0:
                dlina += 1
            else:
                ans2 = 0
                dlina = 0
            maxim = max(maxim ,ans2)
        else:
            maxim = max(maxim, sum(a[0:m-1]), sum(a[1:]))
            break
    if maxim >= ans1:
        print("NO")
    else:
        print("YES")

