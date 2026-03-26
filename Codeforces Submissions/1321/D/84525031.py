from collections import *
import math

INF = (1<<60)

def main():
    N,M = map(int,input().split(' '))
    adjl = [list() for _  in range(N)]
    adjltrans = [list() for _  in range(N)]
    for _ in range(M):
        u,v = map(int,input().split(' '))
        adjl[u-1].append(v-1)
        adjltrans[v-1].append(u-1)

    K = int(input())
    path = list(map(lambda x: int(x)-1, input().split(' ')))

    dist = bfs(N,M,adjltrans,path[-1])
    max_reb = 0
    min_reb = 0
    for pidx in range(1,K):
        prev = path[pidx-1]
        p = path[pidx]
        if dist[p] >= dist[prev]:
            min_reb += 1
            max_reb += 1
        else:
            opp = False
            for adj in adjl[prev]:
                if adj != p and dist[adj]==dist[p]:
                    opp = True
            if opp:
                max_reb += 1

    print(min_reb,max_reb)


def bfs(N, M, adjl, src):
    q = deque()
    dist = [-1 for _ in range(N)]
    vis = [False for _ in range(N)]
    q.append((src,0))
    dist[src] = 0
    vis[src] = True
    while len(q) > 0:
        cur, dst = q.popleft()
        for adj in adjl[cur]:
            if not vis[adj]:
                dist[adj] = dst+1
                q.append((adj,dst+1))
                vis[adj] = True
    return dist

if __name__ == '__main__':
    main()