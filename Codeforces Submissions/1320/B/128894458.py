'''
t3=
8->6|7(1)->5|4(2)->2|3(3)


'''
from sys import  stdin
input=stdin.readline
from collections import  defaultdict,deque
n,m=map(int,input().strip().split())
g=defaultdict(list)
for _ in range(m):
    x,y=map(int,input().strip().split())
    g[y-1].append(x-1)
a=int(input())
l=list(map(lambda s:int(s)-1,input().strip().split()))
# print(l)
d=[float("inf")]*n
d[l[-1]]=0
par=defaultdict(list)
q=deque([l[-1]])
par2=defaultdict(set)
while q:
    t=q.popleft()
    # print(q)
    for i in g[t]:
        if d[t]+1<d[i]:
            d[i]=d[t]+1
            par[i]=[t]
            q.append(i)
        elif d[t]+1==d[i]:
            par[i].append(t)
mn=0
mx=len(l)-1
for i in range(len(l)-1):
    if d[l[i+1]]!=d[l[i]]-1:
        mn+=1
    if len(par[l[i]])==1 and par[l[i]][0]==l[i+1]:
        mx-=1
print(mn,mx)
