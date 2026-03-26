from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
import threading
import sys
import bisect
# input = sys.stdin.readline
def ri(): return int(input())
def rs(): return input()
def rl(): return list(map(int, input().split()))
def rls(): return list(input().split())


# threading.stack_size(10**8)
# sys.setrecursionlimit(10**6)


def main():
    n, h, l, r = rl()
    a = rl()
    dp = [[-1 << 33 for i in range(n+1)] for i in range(n+1)]

    def ins(x):
        return (l <= x and x <= r)
    dp[0][0] = 0

    cs = 0
    for i in range(n):
        cs += a[i]
        for j in range(n+1):
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+ins((cs-j) % h))
            if j < n:
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+ins((cs-j-1) % h))
    print(max(dp[-1]))
    pass


main()
# threading.Thread(target=main).start()
