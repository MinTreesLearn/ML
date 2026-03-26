class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0]*(self.n+1) # 1-indexed

    def init(self, init_val):
        for i, v in enumerate(init_val):
            self.add(i, v)

    def add(self, i, x):
        # i: 0-indexed
        i += 1 # to 1-indexed
        while i <= self.n:
            self.bit[i] += x
            i += (i & -i)

    def sum(self, i, j):
        # return sum of [i, j)
        # i, j: 0-indexed
        return self._sum(j) - self._sum(i)

    def _sum(self, i):
        # return sum of [0, i)
        # i: 0-indexed
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & (-i)
        return res

class RangeAddBIT:
    def __init__(self, n):
        self.n = n
        self.bit1 = BIT(n)
        self.bit2 = BIT(n)

    def init(self, init_val):
        self.bit2.init(init_val)

    def add(self, l, r, x):
        # add x to [l, r)
        # l, r: 0-indexed
        self.bit1.add(l, x)
        self.bit1.add(r, -x)
        self.bit2.add(l, -x*l)
        self.bit2.add(r, x*r)

    def sum(self, l, r):
        # return sum of [l, r)
        # l, r: 0-indexed
        return self._sum(r) - self._sum(l)

    def _sum(self, i):
        # return sum of [0, i)
        # i: 0-indexed
        return self.bit1._sum(i)*i + self.bit2._sum(i)

    def __str__(self): # for debug
        arr = [self.sum(i,i+1) for i in range(self.n)]
        return str(arr)

n, m = map(int, input().split())
A = list(map(int, input().split()))
A = [a-1 for a in A]

mn = [i for i in range(n)]
for a in A:
    mn[a] = 0

A = list(range(n-1, -1, -1))+A
bit = RangeAddBIT(len(A)+1)
mx = [i for i in range(n)]
prev = [-1]*n
for r, a in enumerate(A):
    l = prev[a]
    mx[a] = max(mx[a], bit.sum(l, l+1))
    bit.add(l+1, r, 1)
    prev[a] = r
for a in range(n):
    l = prev[a]
    mx[a] = max(mx[a], bit.sum(l, l+1))

for i in range(n):
    print(mn[i]+1, mx[i]+1)
