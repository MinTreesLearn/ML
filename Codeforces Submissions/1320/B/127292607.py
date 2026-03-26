"""
Summary of Code:
- Runs bfs from the end with reversed graph to find minimum
    distance from each node to the end node
- Using those information, check if the car is moving in the
    shortest path from the current node to end node

Runtime Complexity:
- input => O(2 * N + M)
- bfs => O(N + M)
- calculating max and min => O(K)
- total => O(2*N + M) + O(N + M) + O(K < N) => O(N + M)

Space Complexity:
- inputs => O(1 + 2 * N)
- dfs => O(maximum depth + N)
- calculating => O(2)
- total => O(1 + 2*N) + O(max depth + N) + O(2) => O(N + maxDepth)

Why the chosen algorithm is good:
- The runtime is O(N+M) and those have maximum of 2*10^5 each
- 4 * 10^5 < 10^7 * 2 thus it would finish in time
"""

from collections import deque
from sys import stdin

def main():
    input = stdin.readline
    N,M = [int(i) for i in input().split()]
    graph = {i+1:set() for i in range(N)}
    rgraph = {i+1:set() for i in range(N)}
    for _ in range(M):
        u,v = [int(i) for i in input().split()]
        graph[u].add(v)
        rgraph[v].add(u)

    k = int(input())
    P = [int(i) for i in input().split()]
    parents = {}
    dist = [float("inf")] * (N+1)
    dist[P[-1]] = 0
    que = deque([P[-1]])
    while que:
        current = que.popleft()
        for next in rgraph[current]:
            if next in parents:
                if dist[current] + 1 == dist[next]:
                    parents[next].add(current)
            else:
                dist[next] = dist[current] + 1
                parents[next] = {current}
                que.append(next)

    mm = [0,0]
    for i in range(k-1):
        if P[i+1] in parents[P[i]]:
            if len(parents[P[i]]) > 1:
                mm[1] += 1
        else:
            mm[0] += 1
            mm[1] += 1
    print(mm[0],mm[1])


if __name__ == '__main__':
    main()
		      	  									 	 		   	 	