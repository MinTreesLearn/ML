from collections import defaultdict, Counter, deque
import threading
import sys
input = sys.stdin.readline
def ri(): return int(input())
def rs(): return input()
def rl(): return list(map(int, input().split()))
def rls(): return list(input().split())


threading.stack_size(10**8)
sys.setrecursionlimit(10**6)


def main():
    n = ri()
    a = [0]+rl()
    for i in range(n+1):
        if i != 0 and a[i] == 0:
            a[i] = -1
    g = defaultdict(list)
    for _ in range(n-1):
        u, v = rl()
        g[u].append(v)
        g[v].append(u)
    par = [-1]*(n+1)
    dp = [0]*(n+1)

    def d1(cn, p):
        par[cn] = p
        dp[cn] = a[cn]
        for nn in g[cn]:
            if nn != p:
                dp[cn] += max(0, d1(nn, cn))
        return dp[cn]
    d1(1, 0)

    def d2(cn, p):
        if cn != 1:
            if dp[cn] > 0:
                res[cn] = max(res[par[cn]], dp[cn])
            else:
                res[cn] = max(res[par[cn]]+dp[cn], dp[cn])
        for nn in g[cn]:
            if nn != p:
                d2(nn, cn)

    res = [0]*(n+1)
    res[1] = dp[1]
    d2(1, 0)
    print(*res[1:])
    pass


# main()
threading.Thread(target=main).start()
