# https://codeforces.com/problemset/problem/1312/D

def f1(n, m):
    # C(m, n-1) * (n-2) * 2^(n-3)
    mod = 998244353

    def power(base, exp):
        val = 1
        while exp:
            if exp & 1:
                val = val * base % mod
            base = base * base % mod
            exp >>= 1
        return val

    a = b = c = 1
    for i in range(1, m + 1):
        a = a * i % mod
        if i == n - 1:
            b = a
        if i == m - n + 1:
            c = a

    ans = (n - 2) * power(2, max(0, n - 3)) % mod
    ans = ans * a % mod
    ans = ans * power(b, mod - 2) % mod
    ans = ans * power(c, mod - 2) % mod
    return ans


# def test():
#     from utils.oj import J
#     import numpy.random as r
#     N = 10
#     M = 10
#     T = 10
#     for t in range(T):
#         n = r.randint(2, N + 1)
#         m = r.randint(1, M + 1)
#         arr = r.randint(1, m + 1, n).tolist()
#         J.satisfy(judge_func=f0, run_func=f1, arr=arr)
#         if t % 100 == 0:
#             print(t)
#     print("ac")
#     exit()


# if __name__ == '__main__':
# from utils.oj import J
#     J.multi(test)
#     test()

n, m = map(int, input().split())
print(f1(n, m))
