import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def main():
    n,k = map(int,input().split())
    edge = [[] for i in range(n)]
    ind = [0]*n
    toid = {}
    for i in range(n-1):
        x,y =map(int, input().split())
        x,y = x-1, y-1
        edge[x].append(y)
        edge[y].append(x)
        ind[x] += 1
        ind[y] += 1
        toid[(x, y)] = i
        toid[(y, x)] = i

    ind.sort()
    import bisect
    ng = 0
    ok = n-1
    while ng+1 < ok:
        c = (ng+ok)//2
        if n-bisect.bisect_left(ind, c+1) <= k:
            ok = c
        else:
            ng = c

    s = []
    s.append(0)
    par = [-1]*n
    order = []
    while s:
        v = s.pop()
        order.append(v)
        for u in edge[v]:
            if par[v] == u:
                continue
            s.append(u)
            par[u] = v

    ans = [-1]*(n-1)
    color = list(range(ok))
    for v in order:
        p = par[v]
        if par[v] != -1:
            color[ans[toid[(p, v)]]], color[-1] = color[-1], color[ans[toid[(p, v)]]]
            cnt = 0
            for u in edge[v]:
                if u == p:
                    continue
                ans[toid[(v, u)]] = color[cnt%ok]
                cnt += 1
            color[ans[toid[(p, v)]]], color[-1] = color[-1], color[ans[toid[(p, v)]]]
        else:
            cnt = 0
            for u in edge[v]:
                ans[toid[(v, u)]] = color[cnt%ok]
                cnt += 1
    print(ok)
    ans = [i+1 for i in ans]
    print(*ans)

if __name__ == '__main__':
    main()
