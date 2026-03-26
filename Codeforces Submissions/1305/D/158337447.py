import sys
input = sys.stdin.buffer.readline 
 
def dfs(n, a, g, p=None):
    parent = [None for i in range(n+1)]
    depth = [[a]]
    parent[a] = a
    if p is not None:
        parent[p] = p
    while True:
        next_s = []
        for x in depth[-1]:
            for y in g[x]:
                if parent[y] is None:
                    parent[y] = x
                    next_s.append(y)
        if len(next_s)==0:
            break
        depth.append(next_s)
    return depth, parent
    
 
def process(n, G):
    g = [[] for i in range(n+1)]
    checked = [0 for i in range(n+1)]
    for a, b in G:
        g[a].append(b)
        g[b].append(a)
    leaves = [i for i in range(1, n+1) if len(g[i])==1]
    for a in leaves:
        if checked[a]==0:
            depth, parent = dfs(n, a, g)
            b = None
            while len(depth) > 0:
                for b2 in depth[-1]:
                    if checked[b2]==0 and b is None:
                        b = b2
                depth.pop()
            if b is None:
                b = leaves[0]
            if True:
                sys.stdout.write(f'? {a} {b}\n')
                sys.stdout.flush()
                r = int(input())
                if (r==a or r==b) and len(g[r])==1:
                    sys.stdout.write(f'! {r}\n')
                    sys.stdout.flush()
                    return
                depth1, parent1 = dfs(n, r, g)
                a_list = [a]
                while a_list[-1] != r:
                    a2 = a_list[-1]
                    a_list.append(parent1[a2])
                b_list = [b]
                while b_list[-1] != r:
                    b2 = b_list[-1]
                    b_list.append(parent1[b2])
                a_list.pop()
                if len(a_list) > 0:
                    a2 = a_list[-1]
                    depth2, parent2 = dfs(n, a2, g, p=r)
                    for row in depth2:
                        for x in row:
                            checked[x] = 1
                b_list.pop()
                if len(b_list) > 0:
                    b2 = b_list[-1]
                    depth3, parent3 = dfs(n, b2, g, p=r)
                    for row in depth3:
                        for x in row:
                            checked[x] = 1
    answer = []
    for i in range(1, n+1):
        if checked[i]==0:
            answer.append(i)
   # print(answer)
    while len(answer) > 1:
        x = answer.pop()
        y = answer.pop()
        sys.stdout.write(f'? {x} {y}\n')
        sys.stdout.flush()
        r = int(input())
        if r==x or r==y:
            sys.stdout.write(f'! {r}\n')
            sys.stdout.flush()
            return
    sys.stdout.write(f'! {answer[0]}\n')
    sys.stdout.flush()
    return
    
    
n = int(input())
G = []
for i in range(n-1):
    a, b = [int(x) for x in input().split()]
    G.append([a, b])
process(n, G)
                