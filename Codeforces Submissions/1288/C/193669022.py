# https://codeforces.com/problemset/problem/1288/C

def f0(n, m):
    mod = int(1e9 + 7)
    c = 2 * m + 1
    dp = [[0] * c for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(n):
        # TODO 空间压缩
        for j in range(c):
            for k in range(j, c):
                d = k - j
                s = (d + 1) * (d + 2) // 2
                e = d + 1
                e = 1
                dp[i + 1][k] = (dp[i + 1][k] + e * dp[i][j]) % mod
    # for v in dp: print(v)
    return dp[-1][-1]


def f1(n, m):
    #
    mod = int(1e9 + 7)

    def power(base, exp):
        val = 1
        while exp:
            if exp & 1:
                val = val * base % mod
            base = base * base % mod
            exp >>= 1
        return val

    a = b = c = 1
    x = 2 * n * m
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


n, m = map(int, input().split())
print(f0(n, m))
