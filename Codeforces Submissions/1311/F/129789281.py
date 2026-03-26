import sys
input = sys.stdin.buffer.readline 

def process(X, V):
    n = len(X)
    A = []
    for i in range(n):
        A.append([X[i], V[i]])
    d = {}
    A1 = sorted(A)
    for i in range(n):
        xi, vi = A1[i]
        d[xi] = i
    A2 = sorted(A, key=lambda a:(a[1], a[0]))
    answer = 0
    S = 0
    for i in range(n):
        xi, vi = A1[i]
        answer+=(i*xi-S)
        S+=xi
    S2 = 0
    for i in range(n):
        x2, v2 = A2[i]
        i1 = d[x2]
        answer+=(i-i1)*x2
    return answer 
    
n = int(input())
X = [int(x) for x in input().split()]
V = [int(x) for x in input().split()]
print(process(X, V))