def solve():
    s, t = input(), input()
    st1, st2 = set(s), set(t)
    for k in st2:
        if k not in st1:
            print(-1); return
    n, m = len(s), len(t)
    dp = [[n]*26 for _ in range(n+1)]
    for i in range(n-1, -1, -1):
        dp[i] = dp[i+1][:]
        dp[i][ord(s[i])-ord('a')] = i
    vis = [False]*m
    ans = 0
    for i in range(m):
        if not vis[i]:
            j = 0
            while j < n and i < m:
                if dp[j][ord(t[i])-97] == n: break
                j = dp[j][ord(t[i])-97]+1
                vis[i] = True
                while i < m and vis[i]: i += 1
            ans += 1
    print(ans)
    

for _ in range(int(input())):
    solve()
