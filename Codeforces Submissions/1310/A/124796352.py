import heapq
import sys
input = sys.stdin.buffer.readline 

def process(A, T):
    d = {}
    n = len(A)
    for i in range(n):
        a = A[i]
        t = T[i]
        if a not in d:
            d[a] = []
        d[a].append(t)
    curr = []
    curr_S = 0
    m = min(d)
    answer = 0
    L = sorted(d)
    n2 = len(L)
    for i in range(n2):
        m = L[i]
        for x in d[m]:
            curr_S+=x
            heapq.heappush(curr, -1*x)
        while len(curr)  > 0 and ((i+1 < n2 and m <  L[i+1]) or (i==n2-1)):
            entry = heapq.heappop(curr)
            entry = entry*-1
            curr_S-=entry
            answer+=(curr_S)
            m+=1
    return answer

n = int(input())
A = [int(x) for x in input().split()]
T = [int(x) for x in input().split()]   
print(process(A, T))  