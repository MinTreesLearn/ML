T = int(input())
for ti in range(T):
    s, t = input().strip(), input().strip()
    N = len(t)
    for i in range(1, N+1):
        dp = [0]+[-1]*i
        for l, c in enumerate(s):
            for j in range(i, -1, -1):
                tmp = dp[j]
                if dp[j] != -1 and i + dp[j] < N and \
                   t[i + dp[j]] == c:
                    tmp = dp[j] + 1
                if j != 0 and t[j-1] == c:
                    tmp = max(tmp, dp[j-1])
                dp[j] = tmp
        if dp[i] == N-i:
            print("YES")
            break
    else:
        print("NO")

