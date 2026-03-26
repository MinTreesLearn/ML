import sys
from collections import deque


def solve():
    n, m, k = map(int, input().split())
    alist = map(int, sys.stdin.readline().split())

    graph = []
    for _ in range(n + 1):
        graph.append([])

    dis_from_start = [-1] * (n + 1)
    dis_from_end = [-1] * (n + 1)

    for _ in range(m):
        x, y = map(int, sys.stdin.readline().split())
        graph[x].append(y)
        graph[y].append(x)

    que = deque()
    que.append(1)
    dis_from_start[1] = 0
    while que:
        now = que.popleft()

        for v in graph[now]:
            if dis_from_start[v] == -1:
                dis_from_start[v] = dis_from_start[now] + 1
                que.append(v)

    que.append(n)
    dis_from_end[n] = 0
    while que:
        now = que.popleft()

        for v in graph[now]:
            if dis_from_end[v] == -1:
                dis_from_end[v] = dis_from_end[now] + 1
                que.append(v)

    candidates = []
    for v in alist:
        candidates.append((v, dis_from_start[v], dis_from_end[v]))

    candidates.sort(key=lambda x: x[1])
    max_dis_from_end = candidates[len(candidates) - 1][2]
    max_dis = 0
    for i in range(len(candidates) - 2, -1, -1):
        max_dis = max(max_dis, candidates[i][1] + max_dis_from_end + 1)
        max_dis_from_end = max(max_dis_from_end, candidates[i][2])

    print(min(max_dis, dis_from_start[n]))


if __name__ == "__main__":
    solve()
