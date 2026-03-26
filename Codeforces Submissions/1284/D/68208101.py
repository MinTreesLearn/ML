import sys
input = lambda: sys.stdin.readline().rstrip()
 
import time
a = time.time()
ke = (int(a*2**20) % (2**20)) + (2**20)
pp = 100001000000000000021
def rand():
    global ke
    ke = ke ** 2 % pp
    return ((ke >> 30) % (1<<15)) + (1<<15)
 
N = int(input())
W = [rand() for _ in range(N)]
 
A = []
B = []
 
for i in range(N):
    a, b, c, d = map(int, input().split())
    A.append((a+1, b+2, i))
    B.append((c+1, d+2, i))
 
def chk(L):
    NN = 18
    BIT=[0]*(2**NN+1)
    BITC=[0]*(2**NN+1)
    SS = [0]
    CC = [0]
    def addrange(r0, x=1):
        r = r0
        SS[0] += x
        CC[0] += 1
        while r <= 2**NN:
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
    S = []
    for a, b, i in L:
        S.append(a)
        S.append(b)
    S = sorted(list(set(S)))
    D = {s:i for i, s in enumerate(S)}
    L = [(D[a], D[b], i) for a, b, i in L]
    s = 0
    L = sorted(L)
    m = -1
    for a, b, i in L:
        v, c = getvalue(a)
        s += v + c * W[i]
        addrange(b, W[i])
    return s
 
print("YES" if chk(A) == chk(B) else "NO")