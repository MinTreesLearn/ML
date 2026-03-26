from sys import stdin, stdout
import math

n, m = map(int, stdin.readline().rstrip().split(' '))
roads = [[] for _ in range(n)]
roadsTo = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, stdin.readline().rstrip().split(' '))
    u -= 1
    v -= 1
    roads[v].append(u)
    roadsTo[u].append(v)
k = int(stdin.readline().rstrip())
p = list(map(int, stdin.readline().rstrip().split(' ')))
p = [i-1 for i in p]

visited = set([p[k-1]])
lastBatch = set([p[k-1]])
minLen = [0]*n

while len(visited) < n:
    batch = set()
    for i in lastBatch:
        for j in roads[i]:
            if j not in visited:
                visited.add(j)
                minLen[j] = minLen[i]+1
                batch.add(j)
    lastBatch = batch

minChg = 0
maxChg = 0
for i in range(len(p)-1):
    nextUp = minLen[p[i+1]]
    otherQuickest = min([minLen[j]
                         for j in roadsTo[p[i]] if j != p[i+1]]+[999999])
    if otherQuickest < nextUp:
        minChg += 1
        maxChg += 1
    elif otherQuickest == nextUp:
        maxChg += 1

print(str(minChg)+' '+str(maxChg))
