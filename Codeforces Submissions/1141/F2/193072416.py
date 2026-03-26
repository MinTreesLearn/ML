from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
import threading
import sys
import bisect
input = sys.stdin.readline
def ri(): return int(input())
def rs(): return input()
def rl(): return list(map(int, input().split()))
def rls(): return list(input().split())


# threading.stack_size(10**8)
# sys.setrecursionlimit(10**6)


def main():
    n = ri()
    a = rl()
    pos = defaultdict(list)
    for l in range(n):
        cs = 0
        for r in range(l, n):
            cs += a[r]
            pos[cs].append((l, r))
    res = 0
    best = []
    for x in pos.keys():
        pp = sorted(pos[x], key=lambda y: y[1])
        cur = 0
        prev = -1
        now = []
        for l, r in pp:
            if l > prev:
                cur += 1
                now.append((l, r))
                prev = r
        if cur > res:
            res = cur
            best = now
    print(res)
    for l, r in best:
        print(*[l+1, r+1])
    pass


main()
# threading.Thread(target=main).start()
