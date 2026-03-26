from sys import stdin, stdout

input = stdin.readline
# print = stdout.write
import sys
# sys.setrecursionlimit(int(1e9))

from collections import defaultdict


def ii():
    return int(input())


def li():
    return list(map(int, input().split()))


def consecutive_ones(arr, n):
    count = 0

    result = 0

    for i in range(n):

        if (arr[i] == '0'):
            count = 0

        else:

            count += 1
            result = max(result, count)

    return result


def consecutive_zeroes(arr, n):
    count = 0

    result = 0

    for i in range(n):

        if (arr[i] == '1'):
            count = 0

        else:

            count += 1
            result = max(result, count)

    return result

# N = 1_000_001
# mod = int(1e9) + 7

# fac = [1 for i in range(N)]
# inv = [1 for i in range(N)]

# for i in range(1,N):
#     fac[i] = (fac[i-1] * i)%mod

# inv[N-1] = pow(fac[N-1], mod-2, mod)

# for i in range(N-2,-1,-1):
#     inv[i] = (inv[i+1]*(i+1))%mod

# inv(i) = fac(i)^(mod-2)
# inv(i+1) = fac(i+1)^(mod-2)
# inv(i+1) = inv(i) * ((i+1)^(mod-2))
# inv(i) = inv(i+1) * (i+1)

# def ncr(n, r, mod):
#     if r > n or r < 0:
#         return 0
#     res = (fac[n]*inv[r])%mod
#     res = (res*inv[n-r])%mod
#     return res

n,m=li()
s=list(map(str, input().split()))
t=list(map(str, input().split()))
q=ii()
for i in range(q):
    v=ii()
    v-=1
    print(s[v%n]+t[v%m])