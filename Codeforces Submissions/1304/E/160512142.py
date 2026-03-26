from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

def dfs(p ,prev , lvl):

    s = [[p , prev , lvl]]

    while(len(s)):

        p , prev , lvl = s.pop()

        level[p]=lvl

        parent[p][0]=prev

        for i in range(1,21):
            if(parent[p][i - 1] != -1):
                parent[p][i]= parent[ parent[p][i - 1] ][i - 1]


        for i in child[p]:
            if(i == prev):continue

            s.append([i , p , lvl + 1])

def distance(u,v):

    if(level[u] > level[v]):u,v=v,u

    ans = 0
    dist=level[v] - level[u]
    for i in range(20,-1,-1):
        if(dist >> i & 1):
            v=parent[v][i]
            ans += (1 << i)

    if(u==v):return ans
    for i in range(20,-1,-1):
        if(parent[u][i] != parent[v][i]):
            u=parent[u][i]
            v=parent[v][i]
            ans += 2 * (1 << i)

    ans += 2
    return ans

def answer():
    

    for q in range(int(input())):

        x , y , a , b , k = inp()
  
        atox = distance(a , x)
        btox = distance(b , x)
        btoy = distance(b , y)
        atoy = distance(a , y)

        atob = distance(a , b)
        if(atob <= k and (atob & 1) == (k & 1)):
            print("YES")
            continue

        atob = atox + btoy + 1
        if(atob <= k and (atob & 1) == (k & 1)):
            print("YES")
            continue

        atob = atoy + btox + 1
        if(atob <= k and (atob & 1) == (k & 1)):
            print("YES")
            continue
        
        print("NO")

    
for T in range(1):

    n = int(input())

    child = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u , v = map(int,input().split())

        child[u].append(v)
        child[v].append(u)

    parent=[[-1 for i in range(21)] for j in range(n + 1)]
    level=[0 for i in range(n + 1)]
    dfs(1,-1,0)

    answer()
