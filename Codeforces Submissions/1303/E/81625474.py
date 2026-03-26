import sys

readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')


def solve():
    s = list(map(lambda x: x-97, ns()))
    t = list(map(lambda x: x-97, ns()))
    n, m = len(s), len(t)
    nxt = [[n+1]*26 for _ in range(n+2)]
    for i in range(n-1, -1, -1):
        nxt[i] = nxt[i+1][:]
        nxt[i][s[i]] = i
    for b in range(m):
        t1 = t[:b]
        t2 = t[b:]
        dp = [[n+1]*(m-b+1) for _ in range(b+1)]
        dp[0][0] = 0
        for j in range(b+1):
            for k in range(m-b+1):
                if j:
                    dp[j][k] = min(dp[j][k], nxt[dp[j-1][k]][t1[j-1]] + 1)
                if k:
                    dp[j][k] = min(dp[j][k], nxt[dp[j][k-1]][t2[k-1]] + 1)
        # print(s, t1, t2)
        # prn(dp)
        if dp[b][m-b] <= n:
            print('YES')
            return
    print('NO')
    return

# solve()

T = ni()
for _ in range(T):
    solve()
