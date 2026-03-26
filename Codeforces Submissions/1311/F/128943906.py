import sys
def main():
    input = sys.stdin.readline
    _ = int(input())
    *X, = map(int, input().split())
    *V, = map(int, input().split())

    D = {v: i for i, v in enumerate(sorted(set(V)))}
    N = len(D)

    ans = 0
    I = sorted(range(len(X)), key=lambda i: X[i])
    C = BinaryIndexedTree(N)
    S = BinaryIndexedTree(N)
    for i in I:
        x, v = X[i], V[i]
        j = D[v]
        c = C.query(j)
        s = S.query(j)
        ans += x * c - s
        C.add(j, 1)
        S.add(j, x)

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
