def a():
    n = int(input())
    b = list(map(int, input().strip().split()))
    d = {}
    for i in range(n):
        if b[i]-i-1 not in d:
            d[b[i]-i-1] = 0
        d[b[i]-i-1] += b[i]
    ans = -1
    for k in d:
        ans = max(ans, d[k])
    print(ans)
    
a()