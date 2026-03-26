import sys, collections, math, bisect, heapq, random, functools
input = sys.stdin.readline
out = sys.stdout.flush


def solve():
    n,k = map(int,input().split())
    edges = [[] for i in range(n + 1)]
    degree = [0] * (n + 1)
    e = []
    for i in range(n - 1):
        u,v = map(int,input().split())
        e.append([u,v])
        edges[u].append(v)
        edges[v].append(u)
        degree[u] += 1
        degree[v] += 1
    a = list(degree[i] for i in range(1,n + 1))
    a.sort(reverse = True)
    tar = a[k]
    color = collections.defaultdict(lambda :-1)
    queue = collections.deque()
    queue.append([1,1])
    vis = {1}
    while queue:
        cur,c = queue.popleft()
        for next_ in edges[cur]:
            if next_ in vis:
                continue
            vis.add(next_)
            if color[(cur,next_)] == -1:
                color[(cur,next_)] = c
                color[(next_,cur)] = c
                c += 1
                if c > tar:
                    c -= tar
                queue.append([next_,c])


    print(tar)
    ans = []
    for u,v in e:
        ans.append(color[(u,v)])
    print(*ans)


if __name__ == '__main__':
    solve()