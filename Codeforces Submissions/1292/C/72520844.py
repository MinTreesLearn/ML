''' Testing Python performance @Pajenegod's solution '''
INF = 10 ** 10
def main():
    #print = out.append
    ''' Cook your dish here! '''
    # Read input and build the graph
    n = get_int()
    coupl = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = get_list()
        coupl[u-1].append(v-1)
        coupl[v-1].append(u-1)

    # Relabel to speed up n^2 operations later on
    bfs = [0]
    found = [0] * n
    found[0] = 1
    for node in bfs:
        for nei in coupl[node]:
            if not found[nei]:
                found[nei] = 1
                bfs.append(nei)

    new_label = [0] * n
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
        parent = pind // n

        # Update size of (root, parent)
        size[pind] += size[ind]

        # Update DP value of (root, parent)
        DP[pind] = max(DP[pind], max(DP[ind], DP[ind2]) + size[ind] * size[ind2])
    print(max(DP[root * n + root] for root in range(n)))

''' Pythonista fLite 1.1 '''
import sys
#from collections import defaultdict, Counter, deque
# from bisect import bisect_left, bisect_right
# from functools import reduce
# import math
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
out = []
get_int = lambda: int(input())
get_list = lambda: list(map(int, input().split()))
main()
#[main() for _ in range(int(input()))]
print(*out, sep='\n')
