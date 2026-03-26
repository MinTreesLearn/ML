
import sys
from sys import stdin

from collections import deque
def NC_Dij(lis,start):

    ret = [float("inf")] * len(lis)
    ret[start] = 0
    visit = []
    
    q = deque([start])
    plis = [i for i in range(len(lis))]

    while len(q) > 0:
        now = q.popleft()
        visit.append(now)

        for nex in lis[now]:

            if ret[nex] > ret[now] + 1:
                ret[nex] = ret[now] + 1
                plis[nex] = now
                q.append(nex)

    return ret,plis,visit

n = int(stdin.readline())

lis = [ [] for i in range(n) ]

for i in range(n-1):
    a,b = map(int,stdin.readline().split())
    a -= 1
    b -= 1
    lis[a].append(b)
    lis[b].append(a)

dlis,plis,visit = NC_Dij(lis,0)

top3 = [ [] for i in range(n) ]
ans = 0
ansx = [0,1,2]

visit.reverse()

for v in visit:

    np = plis[v]
    top3[v].append( (0,-1,v) )
    top3[v].sort()
    top3[v].reverse()
    while len(top3[v]) > 3:
        del top3[v][-1]

    if np != v:
        nedge , _ , stx = top3[v][0]
        top3[np].append( (nedge+1 , v , stx) )

visit.reverse()
for v in visit:

    np = plis[v]
    #top3[v].append( (0,v,v) )
    if np != v:
        for ec,cv,stx in top3[np]:
            if cv != v:
                top3[v].append( (ec+1,-2,stx) )
                break
    top3[v].sort()
    top3[v].reverse()
    while len(top3[v]) > 3:
        del top3[v][-1]

    nans = 0
    nx = []
    for ec,_,stx in top3[v]:
        nans += ec
        nx.append(stx)

    if ans < nans and len(nx) == 3 :
        ans = nans
        ansx = nx
    

print (ans)
for i in range(3):
    ansx[i] += 1
print (*ansx)
