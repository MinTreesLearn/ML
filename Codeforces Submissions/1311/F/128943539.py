from itertools import accumulate
import sys
def main():
    input = sys.stdin.readline
    _ = int(input())
    *X, = map(int, input().split())
    *V, = map(int, input().split())

    zero, pos, neg = [], [], []
    for x, v in zip(X, V):
        if v == 0: zero.append((x, v))
        elif v > 0: pos.append((x, v))
        else: neg.append((x, v))
    zero.sort()
    presum_zero = [0] + list(accumulate(x for x, _ in zero))
    pos.sort()
    neg.sort()
    presum_neg = [0] + list(accumulate(x for x, _ in neg))

    X = sorted(set(X))
    D = {x: i for i, x in enumerate(X)}

    ans = 0
    # 0,0
    n = len(zero)
    for i in range(n - 1):
        d = zero[i + 1][0] - zero[i][0]
        l = i + 1
        r = n - l
        ans += d * l * r

    # 0,+ | 0,-
    def zp(Z, A, P):
        res = 0
        i = 0
        n = len(Z)
        for x, _ in P:
            while i < n and Z[i][0] <= x: i += 1
            res += x * i - A[i]
        return res
    ans += zp(zero, presum_zero, pos)
    ans += zp(neg, presum_neg, zero)

    # +,+ | -,-
    def pp(P):
        if len(P) == 0: return 0
        P, V = zip(*P)
        I = sorted(range(len(V)), key=lambda i: V[i])
        C = BinaryIndexedTree(len(X))
        S = BinaryIndexedTree(len(X))
        res = 0
        for i in I:
            x = P[i]
            j = D[x]
            c = C.query(j)
            s = S.query(j)
            res += x * c - s
            C.add(j, 1)
            S.add(j, x)
        return res
    ans += pp(pos)
    ans += pp(neg)

    # +,-
    ans += zp(neg, presum_neg, pos)

    print(ans)

class BinaryIndexedTree:
    __slots__ = ('__n', '__d', '__f', '__id')

    def __init__(self, n=None, f=lambda x, y: x + y, identity=0, initial_values=None):
        assert(n or initial_values)
        self.__f, self.__id, = f, identity
        self.__n = len(initial_values) if initial_values else n
        self.__d = [identity] * (self.__n + 1)
        if initial_values:
            for i, v in enumerate(initial_values): self.add(i, v)

    def add(self, i, v):
        n, f, d = self.__n, self.__f, self.__d
        i += 1
        while i <= n:
            d[i] = f(d[i], v)
            i += -i & i

    def query(self, r):
        res, f, d = self.__id, self.__f, self.__d
        r += 1
        while r:
            res = f(res, d[r])
            r -= -r & r
        return res

if __name__ == '__main__':
    main()
