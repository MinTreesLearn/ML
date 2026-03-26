import sys
input = lambda: sys.stdin.readline().rstrip()

from bisect import bisect_right as br

ke = 1333333333
pp = 1000000000001003
def rand():
    global ke
    ke = ke ** 2 % pp
    return ((ke >> 10) % (1<<15)) + (1<<15)

N = int(input())
W = [rand() for _ in range(N)]

A = []
B = []

for i in range(N):
    a, b, c, d = map(int, input().split())
    A.append((a+2, b+3, i))
    B.append((c+2, d+3, i))

def chk(L):
    S = [1]
    for a, b, i in L:
        S.append(b)
    S = sorted(list(set(S)))
    D = {s:i for i, s in enumerate(S)}
    L = [(D[S[br(S, a)-1]], D[b], i) for a, b, i in L]
    L = sorted(L)
    nn = 101010
    BIT = [0] * nn
    BITC = [0] * nn
    SS = [0]
    CC = [0]
    def addrange(r0, x=1):
        r = r0
        SS[0] += x
        CC[0] += 1
        while r <= nn:
            BIT[r] -= x
            BITC[r] -= 1
            r += r & (-r)
    def getvalue(r):
        a = 0
        c = 0
        while r != 0:
            a += BIT[r]
            c += BITC[r]
            r -= r&(-r)
        return (SS[0] + a, CC[0] + c)
    s = 0
    m = -1
    for a, b, i in L:
        v, c = getvalue(a)
        s += v + c * W[i]
        addrange(b, W[i])
    return s

print("YES" if chk(A) == chk(B) else "NO")