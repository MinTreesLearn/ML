import sys
input = sys.stdin.buffer.readline 
 
def find_root(root_dict, x):
    L = []
    while x != root_dict[x]:
        L.append(x)
        x = root_dict[x]
    for y in L:
        root_dict[y] = x
    return x
 
def find_path(parent_dict, a, b):
    L1 = [a]
    L_set = {a: 0}
    L2 = [b]
    while L1[-1] is not None:
        a_parent = parent_dict[L1[-1]]
        L_set[a_parent] = len(L1)
        L1.append(a_parent)
        if L1[-1]==b:
            return L1
    while L2[-1] not in L_set:
        b_parent = parent_dict[L2[-1]]
        L2.append(b_parent)
    c = L_set[L2[-1]]
    L = L1[:c]+L2[::-1]
    return L
    
def process(G, A):
    n = len(G)+1
    g = [{} for i in range(n+1)]
    root_dict = [i for i in range(n+1)]
    answer = [0 for i in range(n-1)]
    pair_dict = {}
    for a, b, g2 in A:
        if a not in pair_dict:
            pair_dict[a] = {}
        if b not in pair_dict:
            pair_dict[b] = {}
        if b in pair_dict[a] and pair_dict[a][b] != g2:
            return [-1]
        pair_dict[a][b] = g2
        pair_dict[b][a] = g2
    for i in range(n-1):
        x, y = G[i]
        g[x][y] = i
        g[y][x] = i
    A.sort(key=lambda a:a[2])
    #1. Do BFS to make finding paths easier.
    parent_dict = [0 for i in range(n+1)]
    parent_dict[1] = None
    start = [1]
    while len(start) > 0:
        next_s = []
        for x in start:
            for y in g[x]:
                if parent_dict[y]==0:
                    parent_dict[y] = x
                    next_s.append(y)
        start = next_s
    while len(A) > 0:
        ai, bi, gi = A.pop()
        a2 = find_root(root_dict, ai)
        b2 = find_root(root_dict, bi)
        if a2 != b2:
            #if they're different
            #then we can definitely make it work
            #1a. Find path from a2 to b2
            L = find_path(parent_dict, a2, b2)
            #2. Make all the edges on L equal to gi
            for i in range(len(L)-1):
                c1, c2 = L[i], L[i+1]
                i2 = g[c1][c2]
                if answer[i2] != 0 and answer[i2] != gi:
                    return [-1]
                answer[i2] = gi
            #3. Combine all the nodes on that path together, because we get them.
            #3a. Associate all the nodes with a2
            for ci in L:
                root_dict[ci] = a2
            #3b. Add the neighbors of the other nodes to the neighbors of a2
            #and vice-versa
            for ci in L:
                if ci != a2:
                    #ci to be merged into a2
                    if parent_dict[ci] is None:
                        parent_dict[a2] = None
                    for y in g[ci]:
                        if root_dict[y] != a2:
                            #if y-a2 and y NOT to be merged into a2
                            if parent_dict[y]==ci:
                                parent_dict[y] = a2
                            if parent_dict[ci]==y:
                                parent_dict[a2] = y
                            j = g[ci][y]
                            if ci in g[y]:
                                g[y].pop(ci)
                            g[y][a2] = j
                            g[a2][y] = j
                    g[ci] = {}
                    if ci in g[a2]:
                        g[a2].pop(ci)
            for ci in L:
                if ci != a2:
                    if ci in pair_dict:
                        for y in pair_dict[ci]:
                            if y in pair_dict:
                                g2 = pair_dict[ci][y]
                                if y==a2 and g2 < gi:
                                    return [-1]
                                elif y != a2:
                                    if a2 in pair_dict[y] and pair_dict[y][a2] != g2:
                                        return [-1]
                                    pair_dict[y][a2] = g2
                                    pair_dict[a2][y] = g2
                        pair_dict.pop(ci)
                        if a2 in pair_dict and ci in pair_dict[a2]:
                            pair_dict[a2].pop(ci)
           # print(ai, bi, g, parent_dict)
                        
    for i in range(n-1):
        if answer[i]==0:
            answer[i] = 1
    return answer
 
n = int(input())
G = []
for i in range(n-1):
    x, y = [int(x) for x in input().split()]
    G.append([x, y])
m = int(input())
A = []
for i in range(m):
    a, b, g = [int(x) for x in input().split()]
    A.append([a, b, g])
answer = process(G, A)
sys.stdout.write(' '.join(map(str, answer))+'\n')