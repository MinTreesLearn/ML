def f0(n, m):
    mod = int(1e9 + 7)
    c = 2 * m + 1
    dp = [[0] * c for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(n):
        # TODO 空间压缩 / 斜率优化
        for j in range(c):
            for k in range(j, c):
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod
    return dp[-1][-1]


def f1(n, m):
    def power(base, exp):
        val = 1
        while exp:
            if exp & 1:
                val = val * base % mod
            base = base * base % mod
            exp >>= 1
        return val

    mod = int(1e9 + 7)
    a = b = c = 1
    x = n + m * 2 - 1
    y = 2 * m
    z = x - y
    for i in range(1, x + 1):
        a = a * i % mod
        if i == y:
            b = a
        if i == z:
            c = a
    ans = a
    ans = ans * power(b, mod - 2) % mod
    ans = ans * power(c, mod - 2) % mod
    return ans


# import numpy.random as r
#
# for _ in range(1000):
#     n, m = r.randint(1, 1000, 2)
#     r0 = f0(n, m)
#     r1 = f1(n, m)
#     # print(n, m)
#     if r0 != r1:
#         print("!!!!!", r0, r1)
#         exit(1)
# exit()

n, m = map(int, input().split())
print(f0(n, m))
