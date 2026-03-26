def ddfs(root):
    global count
    global flag
    visit=[0]*(n+1)
    stack=[0,root]
    stack2=[]
    while(len(stack)>1):
        par=stack.pop()
        stack2.append(par)
        if(visit[par]):
            continue
        visit[par]=1
        for i in graph[par]:
            if(visit[i]==0):
                stack.append(i)
    visited=[0]*(n+1)
    while(len(stack2)>1):
        q = stack2.pop()
        if(count[q]<under[q]):
            flag=1
        visited[q]=1
        for i in graph[q]:
            if(visited[i]==0):
                count[i]+=count[q]+1


def dfs(root):
    stack=[root]
    visit=[0]*(n+1)

    while(stack):
        par=stack.pop()
        if(visit[par]):
            continue
        yy = seg_queries(under[par]+1,store - 1)
        final[par]=yy
        seg_update(store-1+yy)
        visit[par]=1
        for i in graph[par]:
            if(visit[i]==0):
                stack.append(i)

def seg_update(yy):
    seg_tree[yy]=0
    while(yy>1):
        yy=(yy>>1)
        seg_tree[yy]=seg_tree[yy<<1]+seg_tree[(yy<<1)+1]

def seg_queries(p,y):
    x=1
    if(seg_tree[x]<p):
        return -1
    while(x<=y):
        if(seg_tree[x<<1]>=p):
            x=x<<1
        else:
            p -= seg_tree[x << 1]
            x=(x<<1)+1

    return (x-y)

def seg_build(x):
    while(x>=1):
        seg_tree[x]=seg_tree[x<<1]+seg_tree[(x<<1)+1]
        x-=1

n=int(input())
flag=0
graph=[[] for i in range(n+1)]
under=[0 for i in range(n+1)]
for i in range(1,n+1):
    a,b=map(int,input().split())
    under[i]=b
    if(a==0):
        root=i
    else:
        graph[a].append(i)
        graph[i].append(a)
count=[0]*(n+1)
ddfs(root)
i=1
while(i<n):
    i=i<<1
store=i
seg_tree=[0 for j in range(store<<1)]
for j in range(store,store+n):
    seg_tree[j]=1
final=[0 for i in range(n+1)]
seg_build(store-1)
dfs(root)
if(flag==0):
    print("YES")
    print(*final[1:])
else:
    print("NO")