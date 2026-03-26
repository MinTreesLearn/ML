import sys
readline = sys.stdin.readline
class Lazysegtree:
    #RAQ
    def __init__(self, A, intv, initialize = True, segf = min):
        #区間は 1-indexed で管理
        self.N = len(A)
        self.N0 = 2**(self.N-1).bit_length()
        self.intv = intv
        max = segf
        self.lazy = [0]*(2*self.N0)
        if initialize:
            self.data = [intv]*self.N0 + A + [intv]*(self.N0 - self.N)
            for i in range(self.N0-1, 0, -1):
                self.data[i] = max(self.data[2*i], self.data[2*i+1]) 
        else:
            self.data = [intv]*(2*self.N0)

    def _ascend(self, k):
        k = k >> 1
        c = k.bit_length()
        for j in range(c):
            idx = k >> j
            self.data[idx] = max(self.data[2*idx], self.data[2*idx+1]) \
            + self.lazy[idx]
            
    def _descend(self, k):
        k = k >> 1
        idx = 1
        c = k.bit_length()
        for j in range(1, c+1):
            idx = k >> (c - j)
            ax = self.lazy[idx]
            if not ax:
                continue
            self.lazy[idx] = 0
            self.data[2*idx] += ax
            self.data[2*idx+1] += ax
            self.lazy[2*idx] += ax
            self.lazy[2*idx+1] += ax
    
    def query(self, l, r):
        L = l+self.N0
        R = r+self.N0
        Li = L//(L & -L)
        Ri = R//(R & -R)
        self._descend(Li)
        self._descend(Ri - 1)
        
        s = self.intv                                                              
        while L < R:
            if R & 1:
                R -= 1
                s = max(s, self.data[R])
            if L & 1:
                s = max(s, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return s
    
    def add(self, l, r, x):
        L = l+self.N0
        R = r+self.N0

        Li = L//(L & -L)
        Ri = R//(R & -R)
        
        while L < R :
            if R & 1:
                R -= 1
                self.data[R] += x
                self.lazy[R] += x
            if L & 1:
                self.data[L] += x
                self.lazy[L] += x
                L += 1
            L >>= 1
            R >>= 1
        
        self._ascend(Li)
        self._ascend(Ri-1)
    
    def binsearch(self, l, r, check, reverse = False):
        L = l+self.N0
        R = r+self.N0
        Li = L//(L & -L)
        Ri = R//(R & -R)
        self._descend(Li)
        self._descend(Ri-1)
        SL, SR = [], []
        while L < R:
            if R & 1:
                R -= 1
                SR.append(R)
            if L & 1:
                SL.append(L)
                L += 1
            L >>= 1
            R >>= 1
        
        if reverse:
            for idx in (SR + SL[::-1]):
                if check(self.data[idx]):
                    break
            else:
                return -1
            while idx < self.N0:
                ax = self.lazy[idx]
                self.lazy[idx] = 0
                self.data[2*idx] += ax
                self.data[2*idx+1] += ax
                self.lazy[2*idx] += ax
                self.lazy[2*idx+1] += ax
                idx = idx << 1
                if check(self.data[idx+1]):
                    idx += 1
            return idx - self.N0
        else:
            for idx in (SL + SR[::-1]):
                if check(self.data[idx]):
                    break
            else:
                return -1
            while idx < self.N0:
                ax = self.lazy[idx]
                self.lazy[idx] = 0
                self.data[2*idx] += ax
                self.data[2*idx+1] += ax
                self.lazy[2*idx] += ax
                self.lazy[2*idx+1] += ax
                idx = idx << 1
                if not check(self.data[idx]):
                    idx += 1
            return idx - self.N0


N, M, P = map(int, readline().split())
xcx = [tuple(map(int, readline().split())) for _ in range(N)]
ycy = [tuple(map(int, readline().split())) for _ in range(M)]
enemy = [tuple(map(int, readline().split())) for _ in range(P)]
JM = 10**6+4

table = [0]*JM
bestarmor = [2147483648]*JM
bestweapon = [2147483648]*JM
event = [[] for _ in range(JM)]
for y, cy in ycy:
    bestarmor[y] = min(bestarmor[y], cy)
for x, cx in xcx:
    bestweapon[x] = min(bestweapon[x], cx)

for i in range(JM):
    if bestarmor[i] != 2147483648:
        table[i] -= bestarmor[i]
        table[i+1] += bestarmor[i]
    table[i] += table[i-1]
table = [t if t else -2147483648 for t in table]

for x, y, z in enemy:
    event[x+1].append((y+1, z))

T = Lazysegtree(table, -2147483648, initialize = True, segf = max)
cnt = 0
N0 = T.N0
ans = -2147483648
for i in range(JM):
    for y, z in event[i]:
        T.add(y, N0, z)
    if bestweapon[i] == 2147483648:
        continue
    else:
        ans = max(ans, T.data[1] - bestweapon[i])
print(ans)
