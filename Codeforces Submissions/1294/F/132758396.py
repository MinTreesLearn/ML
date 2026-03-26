import sys, collections, math, bisect, heapq
input = sys.stdin.readline


n = int(input())
edges = collections.defaultdict(list)
for i in range(n - 1):
    u,v = map(int,input().split())
    edges[u].append(v)
    edges[v].append(u)

# 找到树的直径
def bfs1():
    queue = collections.deque()
    node1,dis1,node2,dis2 = 0,-1,0,-1
    queue.append([1,0])
    vis = {1}
    while queue:
        cur,d = queue.popleft()
        if dis1 < d:
            dis1 = d
            node1 = cur
        for next_ in edges[cur]:
            if next_ not in vis:
                vis.add(next_)
                queue.append([next_,d + 1])

    vis.clear()
    queue.append([node1,0])
    vis.add(node1)
    while queue:
        cur,d = queue.popleft()
        if dis2 < d:
            dis2 = d
            node2 = cur
        for next_ in edges[cur]:
            if next_ not in vis:
                vis.add(next_)
                queue.append([next_,d + 1])
    return node1,node2,dis2

node1,node2,diameter = bfs1()

# bfs找到距离最远的点
def bfs2(u):
    queue = collections.deque()
    dis = [-1] * n
    dis[u - 1] = 0
    queue.append([u,0])
    while queue:
        cur,d = queue.popleft()
        for next_ in edges[cur]:
            if dis[next_ - 1] == -1:
                dis[next_ - 1] = d + 1
                queue.append([next_,d + 1])
    return dis

c1,c2 = bfs2(node1),bfs2(node2)

# 枚举中间点
node3 = -1
dis = 0
for i in range(n):
    if i + 1 == node1 or i + 1 == node2:
        continue
    temp = c1[i] + c2[i]
    if temp > dis:
        dis = temp
        node3 = i + 1
print((diameter + dis) // 2)
print(node1,node2,node3)























