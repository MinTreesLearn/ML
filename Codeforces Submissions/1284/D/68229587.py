import sys
input = lambda: sys.stdin.readline().rstrip()
 
ke = 133333333
pp = 1000000000001003
def rand():
    global ke
    ke = ke ** 2 % pp
    return ((ke >> 10) % (1<<20)) + (1<<20)
 
N = int(input())
W = [rand() for _ in range(N)]
 
AL, AR, BL, BR = [], [], [], [] 
for i in range(N):
    a, b, c, d = map(int, input().split())
    AL.append(a)
    AR.append(b)
    BL.append(c)
    BR.append(d)

def chk(L, R):
    S = sorted(list(set(L + R)))
    D = {s:i for i, s in enumerate(S)}
    L = [D[a] for a in L]
    R = [D[a] for a in R]
    X = [0] * 200200
    for i, l in enumerate(L):
        X[l] += W[i]
    for i in range(1, 200200):
        X[i] += X[i-1]
    
    s = 0
    for i, r in enumerate(R):
        s += X[r] * W[i]
    return s
 
print("YES" if chk(AL, AR) == chk(BL, BR) else "NO")