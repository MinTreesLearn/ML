import sys
readline = sys.stdin.readline

from itertools import accumulate 
class Lazysegtree:
    #RAQ
    def __init__(self, A, intv, initialize = True, segf = min):
        #区間は 1-indexed で管理
        self.N = len(A)
        self.N0 = 2**(self.N-1).bit_length()
        self.intv = intv
        self.segf = segf
        self.lazy = [0]*(2*self.N0)
        if initialize:
            self.data = [intv]*self.N0 + A + [intv]*(self.N0 - self.N)
            for i in range(self.N0-1, 0, -1):
                self.data[i] = self.segf(self.data[2*i], self.data[2*i+1]) 
        else:
            self.data = [intv]*(2*self.N0)

    def _ascend(self, k):
        k = k >> 1
        c = k.bit_length()
        for j in range(c):
            idx = k >> j
            self.data[idx] = self.segf(self.data[2*idx], self.data[2*idx+1]) \
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
                s = self.segf(s, self.data[R])
            if L & 1:
                s = self.segf(s, self.data[L])
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


N = int(readline())
P = list(map(lambda x:int(x)-1 , readline().split()))
Pinv = [None]*N
for i in range(N):
    Pinv[P[i]] = i
A = list(map(int, readline().split()))

dp = A[:-1]
for i in range(1, N-1):
    dp[i] += dp[i-1]

inf = 1<<60
ans = dp[0]
dp = Lazysegtree(dp, inf, initialize = True, segf = min)

N0 = dp.N0
cnt = 0
for i in range(N):
    a = A[Pinv[i]]
    p = Pinv[i]
    dp.add(p, N0, -2*a)
    cnt += a
    ans = min(ans, cnt + dp.query(0, N0))
print(ans)



