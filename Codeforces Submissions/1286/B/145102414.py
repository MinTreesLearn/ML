import sys
from sys import stdin

from collections import deque
def NC_Dij(lis,start):

    ret = [float("inf")] * len(lis)
    ret[start] = 0
    
    q = deque([start])
    plis = [i for i in range(len(lis))]

    while len(q) > 0:
        now = q.popleft()

        for nex in lis[now]:

            if ret[nex] > ret[now] + 1:
                ret[nex] = ret[now] + 1
                plis[nex] = now
                q.append(nex)

    return ret,plis

n = int(stdin.readline())

lis = [ [] for i in range(n)]
clis = [None] * n

for i in range(n):

    p,c = map(int,stdin.readline().split())
    p -= 1

    clis[i] = c
    if p != -1:
        lis[p].append(i)
    else:
        root = i

dlis,_ = NC_Dij(lis,root)

dv = [ (dlis[i],i) for i in range(n) ]
dv.sort()
dv.reverse()

ans = [ [] for i in range(n) ]

for d,v in dv:

    flag = False
    if clis[v] == 0:
        ans[v].append(v)
        flag = True

    for nex in lis[v]:
        for tv in ans[nex]:
            ans[v].append(tv)
            if len(ans[v]) == clis[v]:
                ans[v].append(v)
                flag = True

    if not flag:
        print ("NO")
        sys.exit()

#print (ans)

rans = [None] * n
for i in range(n):
    rans[ ans[root][i] ] = i+1

print ("YES")
print (" ".join(map(str,rans)))
