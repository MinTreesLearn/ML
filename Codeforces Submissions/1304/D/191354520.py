from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
import threading
import sys
# input = sys.stdin.readline
def ri(): return int(input())
def rs(): return input()
def rl(): return list(map(int, input().split()))
def rls(): return list(input().split())


# threading.stack_size(10**8)
# sys.setrecursionlimit(10**6)


def main():
    for _ in range(ri()):
        n, s = rls()
        n = int(n)
        res = [0]*n
        cur = n
        prev = -1
        for i in range(n):
            if i == n-1 or s[i] == '>':
                for j in range(i, prev, -1):
                    res[j] = cur
                    cur -= 1
                prev = i
        print(' '.join(map(str, res)))
        res = [0]*n
        cur = 1
        prev = -1
        for i in range(n):
            if i == n-1 or s[i] == '<':
                for j in range(i, prev, -1):
                    res[j] = cur
                    cur += 1
                prev = i
        print(' '.join(map(str, res)))
    pass


main()
# threading.Thread(target=main).start()
