# Time complexity: O(n)
# Space complexity: O(n)
# The solution iterates through each vertex and edge once O(n + m)
# Then it iterates through each node it travels and its edge O(k + m)
import math

n, m = map(int, input().strip().split())
outadj = [set() for _ in range(n + 1)]
inadj = [set() for _ in range(n + 1)]
cost = [math.inf] * (n + 1)
discovered = [False] * (n + 1)
for _ in range(m):
    u, v = map(int, input().strip().split())
    outadj[u].add(v)
    inadj[v].add(u)
k = int(input())
path = list(map(int, input().strip().split()))
src = path[0]
dest = path[-1]

q = [dest]
cost[dest] = 0
discovered[dest] = True
while len(q) != 0:
    u = q.pop(0)
    for v in inadj[u]:
        if discovered[v]:
            continue
        discovered[v] = True
        cost[v] = cost[u] + 1
        q.append(v)

minim = 0
maxim = 0
for i in range(k - 1):
    # if not the shortest path
    if cost[path[i]] - 1 != cost[path[i+1]]:
        minim += 1
        maxim += 1
    else:
        # find alternative shortest paths
        for v in outadj[path[i]]:
            if cost[path[i]] - 1 == cost[v] and v != path[i+1]:
                maxim += 1
                break

print(minim, maxim)
 	 					      				  	 	   	