import sys
input = sys.stdin.buffer.readline 

def process_root(g, r):
    start = [r]
    seen = {r: 0}
    parent = {r: None}
    while len(start) > 0:
        next_s = []
        for x in start:
            for y in g[x]:
                if y not in seen:
                    seen[y] = seen[x]+1
                    parent[y] = x
                    next_s.append(y)
        start = next_s
    return seen, parent 

def find_diameter(g):
    for x in g:
        break
    seen, parent = process_root(g, x)
    my_max = [0, x]
    for y in seen:
        if seen[y] > my_max[0]:
            my_max = [seen[y], y]
    a = my_max[1]
    seen, parent = process_root(g, a)
    my_max = [0, a]
    for y in seen:
        if seen[y] > my_max[0]:
            my_max = [seen[y], y]
    c = my_max[1]
    L = [c]
    while L[-1] != a:
        x = parent[L[-1]]
        L.append(x)
    return L, parent


def process(G):
    #we want three vertices a b c to maximize edges on paths between them
    #if b is on path from a to c then we don't get helped.
    #so none of them is on the path between the other two.
    #say path from b to a intersects path from c to a at x
    #a0 = a, a1, a2, a3, ..., ak = c
    #x =ai , 0 < i < k
    #a, c = diameter of tree
    #b = longest branch off diameter?
    g = {}
    n = len(G)
    for i in range(n):
        a, b = G[i]
        if a not in g:
            g[a] = set([])
        if b not in g:
            g[b] = set([])
        g[a].add(b)
        g[b].add(a)
    L, parent = find_diameter(g)
    a, c = L[0], L[-1]
    b = L[1]
    L = set(L)
    distance = {}
    answer = [0, None]
    for x in g:
        if len(g[x])==1 and x != a and x != c:
            L2 = [x]
            while L2[-1] not in distance:
                L2.append(parent[L2[-1]])
                if L2[-1] in L:
                    distance[L2[-1]] = 0
                    break
            L2.pop()
            while len(L2) > 0:
                x2 = L2.pop()
                distance[x2] = distance[parent[x2]]+1
            answer = max([distance[x], x], answer)
    if answer[1] is None:
        path_length = len(L)-1
        return [path_length, a, b, c]
    else:
        b = answer[1]
        path_length = len(L)-1+answer[0]
        return [path_length, a, b, c]
                
          
n = int(input())
G = []
for i in range(n-1):
    a, b = [int(x) for x in input().split()]
    G.append([a, b])
path_length, a, b, c = process(G)
print(path_length)
print(f'{a} {b} {c}')
            