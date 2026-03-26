import heapq
def process(A):
    n = len(A)
    g = [[None, [], None, []] for i in range(n+1)]
    answer = [None for i in range(n)]
    #g[i] = parent of i, children of i, ci, subtree_heap
    for i in range(n):
        pi, ci = A[i]
        if pi==0:
            root = i+1
        g[i+1][0] = pi
        g[i+1][2] = ci
        g[pi][1].append(i+1)
    start = [[root]]
    while True:
        next_s = []
        for x in start[-1]:
            for y in g[x][1]:
                next_s.append(y)
        if len(next_s)==0:
            break
        start.append(next_s)
    while len(start) > 0:
        for x in start[-1]:
            parent, children, ci, subtree_heap = g[x]
            K = len(g[parent][3])
            if ci > len(subtree_heap):
                return ['NO', []]
            I = K+1
            while ci > 0:
                label, index = heapq.heappop(subtree_heap)
                answer[index-1] = I
                heapq.heappush(g[parent][3], (I, index))
                I+=1
                ci-=1
            answer[x-1] = I
            heapq.heappush(g[parent][3], (I, x))
            I+=1
            while len(subtree_heap) > 0:
                label, index = heapq.heappop(subtree_heap)
                answer[index-1] = I
                heapq.heappush(g[parent][3], (I, index))
                I+=1
        start.pop()
    return ['YES', answer]
                
        
        
n = int(input())
A = []
for i in range(n):
    pi, ci = [int(x) for x in input().split()]
    A.append([pi, ci])
a1, a2 = process(A)
print(a1)
if a1=='YES':
    print(' '.join(map(str, a2)))