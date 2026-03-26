
n = int(input())
sz = {}
a = {}
vis = {}
c = {}
g = [[]for i in range(n+10)]
flag = 1

for i in range(1, n+1):
    x, y = map(int, input().split())
    c[i]= y
    g[x].append(i)

def dfs(u):
    global flag
    if u>0:
        sum = 0
        for i in range(1, n+1):
            if i not in vis:
                sum += 1
            if sum == c[u] + 1:
                a[u] = i
                vis[i] = 1
                break
    sz[u] = 1
    for i in range(len(g[u])):
        dfs(g[u][i])
        sz[u] += sz[g[u][i]]
    if u>0 and sz[u]-1 < c[u]:
        flag = 0
    return

dfs(0)

if flag==0:
    print("No")
else:
    print("Yes")
    for i in range(1, 1+n):
        print(a[i], end=' ')