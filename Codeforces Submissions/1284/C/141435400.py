import sys
from itertools import permutations

"""
1 1
2 6
3 32
4 180
5 1116
6 7728
7 59904
8 518400
"""

def solve(N, M):
    ans = 0
    for perm in permutations(range(N)):
        for l in range(N):
            for r in range(N):
                mn = 1e18
                mx = -1e18
                for i in range(l, r+1):
                    mn = min(perm[i], mn)
                    mx = max(perm[i], mx)
                if mx-mn == r-l:
                    ans += 1
                    ans %= M
    return ans

def solve2(N, M):
    # n!/(n P i) = n!/(n!/(n-i)!) = (n-i)!
    fact = [1]
    for i in range(1, N+1):
        fact.append((fact[-1]*i) % M)
    ans = (N*fact[N]) % M
    for len in range(2, N+1):
        tmp = N-len+1
        tmp *= fact[N-len]
        tmp %= M
        tmp *= N-len+1
        tmp %= M
        tmp *= fact[len]
        tmp %= M
        ans += tmp
        if ans >= M: ans -= M
    return ans

toks = sys.stdin.read().split()
N = int(toks[0])
M = int(toks[1])
print(solve2(N, M))
