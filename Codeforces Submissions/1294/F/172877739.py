from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

from collections import deque
"""

it is obv that two vertices are the end points of the tree diameter
we can try all third vertices

"""

def dfs(p , want_update):

    s = [[p , -1 , 0]]
    best = -1
    while(len(s)):

        p , prev , lvl = s.pop()
        if(want_update):
            parent[p] = prev
            level[p] = lvl

        if(best < lvl):
            best = lvl
            node = p

        for i in child[p]:
            if(i == prev):continue
            if(done[i]):continue

            s.append([i , p , lvl + 1])

    return [node , best]

def chain(u , v):

    if(level[u] > level[v]):
        v , u = u , v

    d = level[v] - level[u]
    for i in range(d):
        done[v] = True
        v = parent[v]

    while(u != v):
        done[u] = True
        done[v] = True
        u = parent[u]
        v = parent[v]

    done[u] = True
    

for T in range(1):

    n = int(input())

    child = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u , v = inp()
        child[u].append(v)
        child[v].append(u)


    done = [False for i in range(n + 1)]
    parent = [-1 for i in range(n + 1)]
    level = [0 for i in range(n + 1)]
    a , dist = dfs(1 , True)
    b , dist = dfs(a , False)

    chain(a , b)

    best = -1
    for i in range(1 , n + 1):
        if(not done[i]):continue

        node , d = dfs(i , False)
        if(node == i):continue

        total = dist + d
        if(best < total):
            best = total
            c = node

    if(best == -1):
        best = dist
        for i in range(1 , n + 1):
            if(i != a and i != b):
                c = i
                break

    print(best)
    print(a , b , c)
    
