import sys
 
# Read input and build the graph
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)
 
# Relable to speed up n^2 operations later on
bfs = [0]
found = [0]*n
found[0] = 1
for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)
naming = [0]*n
for i in range(n):
    naming[bfs[i]] = i
 
coupl = [coupl[i] for i in bfs]
for c in coupl:
    c[:] = [naming[x] for x in c]
 
# Precalculations for the DP
subsizes = []
Ps = []
 
for root in range(n):
    P = [-1]*n
    P[root] = root
    bfs = [root]
    for node in bfs:
        for nei in coupl[node]:
            if P[nei] == -1:
                P[nei] = node
                bfs.append(nei)
    Ps += P
    
    subsize = [1]*n
    for node in reversed(bfs[1:]):
        subsize[P[node]] += subsize[node]
 
    other = [0]*n
    for nei in coupl[root]:
        other[nei] = subsize[root] - subsize[nei]
    for node in bfs:
        if P[node] != root:
            other[node] = other[P[node]]
        subsize[node] *= other[node]
    subsizes += subsize
 
# DP using a multisource bfs
DP = [0]*(n * n)
bfs = [n * root + root for root in range(n)]
for ind in bfs:
    root, node = divmod(ind, n)
    for nei in coupl[node]:
        ind2 = ind - node + nei
        if Ps[ind2] == node:
            DP[n * nei + root] = DP[ind2] = max(DP[ind2], DP[ind] + subsizes[ind2])
            bfs.append(ind2)
 
print(max(DP))