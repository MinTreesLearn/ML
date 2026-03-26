# import sys
# sys.stdin = open("input.txt")


cupcakes = []
dp = []


def sol():
    for i in range(1, n):
        dp[i] = max(dp[i - 1] + dp[i], dp[i])


t = int(input())
for _ in range(t):
    n = int(input())
    cupcakes = [*map(int, input().split())]
    n -= 1
    dp = cupcakes[1:]
    sol()
    sol1 = max(dp)
    dp = cupcakes[:-1]
    sol()
    sol2 = max(dp)
    adel = max(sol1, sol2)
    yasser = sum(cupcakes)
    if yasser > adel:
        print("YES")
    else:
        print("NO")
