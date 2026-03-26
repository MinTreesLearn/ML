from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

def query(u , v):

    print('?' , u , v , flush = True)

    return int(input())

def dfs(p , prev):

    yes = True
    for i in child[p]:
        if(done[i]):continue
        if(i == prev):continue

        yes = False
        dfs(i , p)

    if(yes):leafs.append(p)
    

def answer():


    global done , leafs
    done = [False for i in range(n + 1)]
    
    r = 1
    while(1):

        leafs = []
        dfs(r , 0)
        if(leafs[0] == r):return r
        
        if(len(leafs) == 1):
            leafs.append(r)

        r = query(leafs[0] , leafs[1])
        if(r == leafs[0] or r == leafs[1]):
            return r

        done[leafs[0]] = True
        done[leafs[1]] = True
    

for T in range(1):

    n = int(input())

    edges = []
    child = [[] for i in range(n + 1)]

    for i in range(n - 1):

        u , v = inp()
        edges.append([u , v])
        child[u].append(v)
        child[v].append(u)

    print('!' , answer() , flush = True)
    
