import sys
input=sys.stdin.readline
a = [0 for i in range(3505)]
q = int(input())
for _ in range(q):
    n, m, k = map(int, input().split())
    a[1:] = list(map(int, input().split()))
    k = min(k, m-1)
    re, ans = n-k, 0
    for l in range(1, n-re+2):
        r, x, len = l + re - 1, int(1e9), n-m+1
        for i in range(l, r-len+2):
            x = min(x, max(a[i], a[i+len-1]))
        ans = max(ans, x)
    print(ans)