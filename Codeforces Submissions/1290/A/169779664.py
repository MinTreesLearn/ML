import sys, random
input = lambda : sys.stdin.readline().rstrip()


write = lambda x: sys.stdout.write(x+"\n"); writef = lambda x: print("{:.12f}".format(x))
debug = lambda x: sys.stderr.write(x+"\n")
YES="Yes"; NO="No"; pans = lambda v: print(YES if v else NO); INF=10**18
LI = lambda : list(map(int, input().split())); II=lambda : int(input())
def debug(_l_):
    for s in _l_.split():
        print(f"{s}={eval(s)}", end=" ")
    print()
def dlist(*l, fill=0):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [dlist(*ll, fill=fill) for _ in range(l[0])]

### セグメント木(はやい)
class SG:
    def __init__(self, n, v=None):
        self._n = n
        self.geta = 0
        x = 0
        while (1 << x) < n:
            x += 1
        self._log = x
        self._size = 1 << self._log
        self._d = [ninf] * (2 * self._size)
        if v is not None:
            for i in range(self._n):
                self._d[self._size + i] = v[i]
        for i in range(self._size - 1, 0, -1):
            self._update(i)
    def _update(self, k):
        self._d[k] = op(self._d[2 * k], self._d[2 * k + 1])
    def update(self, p, x):
        assert 0 <= p < self._n
#         x -= self.geta
        p += self._size
        self._d[p] = x
        for i in range(1, self._log + 1):
#             self._update(p >> i)
            k = p>>i
            self._d[k] = op(self._d[2 * k], self._d[2 * k + 1])
    def get(self, p):
        assert 0 <= p < self._n
        return self._d[p + self._size] # + self.geta
    def check(self):
        return [self.get(p) for p in range(self._n)]
    def query(self, left, right):
        # [l,r)の総和
        assert 0 <= left <= right <= self._n
        sml = ninf
        smr = ninf
        left += self._size
        right += self._size
        # 外側から計算していく(lは小さい側から, rは大きい側から)
        while left < right:
            if left & 1:
                sml = op(sml, self._d[left])
                left += 1
            if right & 1:
                right -= 1
                smr = op(self._d[right], smr)
            left >>= 1
            right >>= 1
        return op(sml, smr) # + self.geta
#     def update_all(self, v):
#         # 全体加算
#         self.geta += v
    def query_all(self):
        return self._d[1] # + self.geta
    def max_right(self, left, f):
        """f(op(a[l], a[l + 1], ..., a[r - 1])) = true となる最大の r
        -> rはf(op(a[l], ..., a[r]))がFalseになる最小のr
        """
#         assert 0 <= left <= self._n
#         assert f(ninf)
        if left == self._n:
            return self._n
        left += self._size
        sm = ninf
        first = True
        while first or (left & -left) != left:
            first = False
            while left % 2 == 0:
                left >>= 1
            if not f(op(sm, self._d[left])):
                while left < self._size:
                    left *= 2
                    if f(op(sm, self._d[left])):
                        sm = op(sm, self._d[left])
                        left += 1
                return left - self._size
            sm = op(sm, self._d[left])
            left += 1
        return self._n
    def min_left(self, right, f):
        """f(op(a[l], a[l + 1], ..., a[r - 1])) = true となる最小の l
        -> l は f(op(a[l-1] ,..., a[r-1])) が false になる最大の l
        """
#         assert 0 <= right <= self._n
#         assert f(ninf)
        if right == 0:
            return 0
        right += self._size
        sm = ninf
        first = True
        while first or (right & -right) != right:
            first = False
            right -= 1
            while right > 1 and right % 2:
                right >>= 1
            if not f(op(self._d[right], sm)):
                while right < self._size:
                    right = 2 * right + 1
                    if f(op(self._d[right], sm)):
                        sm = op(self._d[right], sm)
                        right -= 1
                return right + 1 - self._size
            sm = op(self._d[right], sm)
        return 0
op = min
ninf = INF

t = II()
for _ in range(t):
    n,m,k = LI()
    k = min(k,m-1)
    a = list(map(int, input().split()))
    vs = []
    for i in range(m):
        v = max(a[i], a[i+(n-m+1)-1])
        vs.append(v)
    sg = SG(m, vs)
    ans = sg.query(0,m)
    for i in range(k+1):
        ans = max(ans, sg.query(i, i+m-k))
    print(ans)