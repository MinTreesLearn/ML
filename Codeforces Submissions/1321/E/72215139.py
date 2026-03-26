from bisect import bisect_right
from operator import itemgetter

# quick input by @pajenegod
import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

class SegmTree:
    def __init__(self, size):
        N = 1
        h = 0
        while N < size:
            N <<= 1
            h += 1
        self.N = N
        self.h = h
        self.t = [0] * (2 * N)
        self.d = [0] * N
    
    def apply(self, p, value):
        self.t[p] += value
        if (p < self.N):
            self.d[p] += value
    
    def build(self, p):
        t = self.t
        d = self.d
        while p > 1:
            p >>= 1
            t[p] = max(t[p<<1], t[p<<1|1]) + d[p]
    
    def rebuild(self):
        t = self.t
        for p in reversed(range(1, self.N)):
            t[p] = max(t[p<<1], t[p<<1|1])
    
    def push(self, p):
        d = self.d
        for s in range(self.h, 0, -1):
            i = p >> s
            if d[i] != 0:
                self.apply(i<<1, d[i])
                self.apply(i<<1|1, d[i])
                d[i] = 0
    
    def inc(self, l, r, value):
        if l >= r:
            return
        
        l += self.N
        r += self.N
        l0, r0 = l, r
        while l < r:
            if l & 1:
                self.apply(l, value)
                l += 1
            if r & 1:
                r -= 1
                self.apply(r, value)
            l >>= 1
            r >>= 1
        self.build(l0)
        self.build(r0 - 1)
    
    def query(self, l, r):
        if l >= r:
            return -float('inf')
        
        t = self.t
        l += self.N
        r += self.N
        self.push(l)
        self.push(r - 1)
        res = -float('inf')
        while l < r:
            if l & 1:
                res = max(res, t[l])
                l += 1
            if r & 1:
                r -= 1
                res = max(t[r], res)
            l >>= 1
            r >>= 1
        return res
 
n, m, p = map(int, input().split())
weapon = []
for _ in range(n):
    a, ca = map(int, input().split())
    weapon.append((a, ca))
 
defense = []
for _ in range(m):
    b, cb = map(int, input().split())
    defense.append((b, cb))
 
monster = []
for _ in range(p):
    x, y, z = map(int, input().split())
    monster.append((x, y, z))
 
weapon.sort(key=itemgetter(0))
defense.sort(key=itemgetter(0))
monster.sort(key=itemgetter(0))
 
st = SegmTree(m)
N = st.N
t = st.t
for i, (b, cb) in enumerate(defense):
    t[i + N] = -cb
st.rebuild()
 
i = 0
maxScore = -float('inf')
for a, ca in weapon:
    st.inc(0, m, -ca)
    while i < p and monster[i][0] < a:
        x, y, z = monster[i]
        goodDef = bisect_right(defense, (y + 1, 0))
        st.inc(goodDef, m, z)
        i += 1
    currScore = st.query(0, m)
    maxScore = max(maxScore, currScore)
    st.inc(0, m, ca)
print(maxScore)
