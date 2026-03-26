from collections import defaultdict, deque
import heapq
import sys
input = sys.stdin.readline

def bfs(s):
    q = deque()
    q.append(s)
    ans = [0] * (n - 1)
    d = defaultdict(lambda : 0)
    d[s] = r
    while q:
        i = q.popleft()
        for j, c in G[i]:
            if not ans[c]:
                d[i] %= r
                d[i] += 1
                ans[c] = d[i]
                d[j] = d[i]
                q.append(j)
    return ans

n, k = map(int, input().split())
G = [[] for _ in range(n + 1)]
for i in range(n - 1):
    x, y = map(int, input().split())
    G[x].append((y, i))
    G[y].append((x, i))
h = []
for i in range(1, n + 1):
    heapq.heappush(h, (-len(G[i]), i))
for _ in range(k):
    l, i = heapq.heappop(h)
r, i = heapq.heappop(h)
r *= -1
ans = bfs(1)
print(r)
print(*ans)