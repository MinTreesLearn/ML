from  collections import deque
from sys import  stdin
input=stdin.readline
#brute
def bfs(source):
    global g,n
    dis=[-1]*n
    q=deque([source])
    dis[source]=0
    while q:
        t=q.popleft()
        for i in g[t]:
            if dis[i]==-1:
                dis[i]=dis[t]+1
                q.append(i)
    return dis
from collections import  defaultdict
g=defaultdict(list)
n,m,k=map(int,input().strip().split())
a=[*map(lambda s:int(s)-1,input().strip().split())]

for i in range(m):
    x,y=map(lambda s:int(s)-1,input().strip().split())
    g[x].append(y)
    g[y].append(x)

ds=bfs(0)
de=bfs(n-1)
cm=ds[-1]
# print(ds)
# print(de)
ds1=[(ds[i],de[i]) for i in a]
ds1.sort(key=lambda s:s[1])
ds1.sort(key=lambda s:s[0])
mx = ds1[0][0]
ans = 0
for i in range(1, k):
	ans = max(mx + ds1[i][1] + 1, ans)
	mx = max(mx, ds1[i][0])
print(min(ans, de[0]))

# print(ds1,de1
