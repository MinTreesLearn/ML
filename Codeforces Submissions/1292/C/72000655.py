import sys
 
# Read input and build the graph
inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
n = inp[ii]; ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)
 
# Relabel to speed up n^2 operations later on
bfs = [0]
found = [0]*n
found[0] = 1
for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)
 
new_label = [0]*n
for i in range(n):
    new_label[bfs[i]] = i
 
coupl = [coupl[i] for i in bfs]
for c in coupl:
    c[:] = [new_label[x] for x in c]
 
##### DP using multisource bfs
 
DP = [0] * (n * n)
size = [1] * (n * n)
P = [-1] * (n * n)
 
# Create the bfs ordering
bfs = [root * n + root for root in range(n)]
for ind in bfs:
    P[ind] = ind
 
for ind in bfs:
    node, root = divmod(ind, n)
    for nei in coupl[node]:
        ind2 = nei * n + root
        if P[ind2] == -1:
            bfs.append(ind2)
            P[ind2] = ind
 
del bfs[:n]
 
# Do the DP
for ind in reversed(bfs):
    node, root = divmod(ind, n)
    ind2 = root * n + node
    pind = P[ind]
    parent = pind//n
    
    # Update size of (root, parent)
    size[pind] += size[ind]
 
    # Update DP value of (root, parent)
    DP[pind] = max(DP[pind], max(DP[ind], DP[ind2]) + size[ind] * size[ind2])
print(max(DP[root * n + root] for root in range(n)))