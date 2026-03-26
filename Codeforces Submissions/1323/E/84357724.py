import io
import os
from math import gcd

from collections import deque, defaultdict, Counter


# TODO: Looked at editorial. I have no idea why this works.
def solve(N, M, C, edges):
    graph = [[] for i in range(N)]
    for l, r in edges:
        graph[r].append(l)
    groups = Counter()
    for r in range(N):
        if graph[r]:
            lefts = tuple(sorted(graph[r]))
            groups[lefts] += C[r]

    g = 0
    for v in groups.values():
        g = gcd(g, v)
    return g


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    T = int(input())
    for t in range(T):
        N, M = [int(x) for x in input().split()]
        C = [int(x) for x in input().split()]
        edges = [[int(x) - 1 for x in input().split()] for i in range(M)]
        burn = input()
        ans = solve(N, M, C, edges)
        print(ans)
