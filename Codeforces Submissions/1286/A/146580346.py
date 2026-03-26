# 1286 A.Garland https://codeforces.com/problemset/problem/1286/A
#

def main():
    n = int(input())
    p = [int(j) for j in input().split()]
    print(solve(n, p))

def solve(n, p):
    dp = [[[float('inf')]*2 for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0][0] = 0
    dp[0][0][1] = 0
    for i in range(1, n+1):
        for j in range(0, i+1):
            if p[i-1]%2 == 0 and j>0:
                dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1)
            if p[i-1]%2 == 1 or p[i-1] == 0:
                dp[i][j][1] = min(dp[i-1][j][0]+1, dp[i-1][j][1])
    return min(dp[n][n//2][0], dp[n][n//2][1])


main()