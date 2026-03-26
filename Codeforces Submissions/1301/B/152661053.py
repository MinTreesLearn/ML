t = int(input())
for i in range(t):
    n = int(input())
    res = 0
    a = list(map(int, input().split()))
    
    mina = float('inf')
    maxa = 0
    res = 0
    for i in range(n):
        if a[i] == -1:
            if i > 0 and a[i-1] != -1:
                mina = min(mina, a[i-1])
                maxa = max(maxa, a[i-1])
            if i < n-1 and a[i+1] != -1:
                mina = min(mina, a[i+1])
                maxa = max(maxa, a[i+1])
    if mina == float('inf'):
        print('{} {}'.format(0, 1))
    else:
        res = (maxa+mina)//2
        ans = 0
        for i in range(n):
            if a[i] == -1:
                a[i] = res
            if i > 0:
                ans = max(ans, abs(a[i]-a[i-1]))
        print('{} {}'.format(ans, res))
        
        
            