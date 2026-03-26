import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


class UnionFind(object):
    __slots__ = ['nodes']

    def __init__(self, n: int):
        self.nodes = [-1] * n

    def find(self, x: int) -> int:
        if self.nodes[x] < 0:
            return x
        else:
            self.nodes[x] = self.find(self.nodes[x])
            return self.nodes[x]

    def unite(self, x: int, y: int) -> bool:
        root_x, root_y, nodes = self.find(x), self.find(y), self.nodes

        if root_x != root_y:
            if nodes[root_x] > nodes[root_y]:
                root_x, root_y = root_y, root_x
            nodes[root_x] += nodes[root_y]
            nodes[root_y] = root_x

        return root_x != root_y

    def size(self, x: int) -> int:
        return -self.nodes[self.find(x)]


border = 1 << 30
mask = border - 1


def add(x1, y1, x2, y2):
    x, y = x1 + x2, y1 + y2
    if y >= border:
        x += 1
        y &= mask
    return x, y


def main():
    n, p, k = map(int, input().split())
    a = list(map(int, input().split()))
    matrix = [list(map(int, input().split())) for _ in range(n)]
    m = 1 << p
    popcnt = [bin(bit).count('1') for bit in range(m)]
    dests = [[i for i in range(p) if ((1 << i) & bit) == 0] for bit in range(m)]
    minf = -10**9

    dp_up = array('i', [0] + [minf] * (m - 1))
    dp_lo = array('i', [0] + [minf] * (m - 1))
    for cnt, i in enumerate(sorted(range(n), key=lambda i: -a[i])):
        ndp_up = dp_up[:]
        ndp_lo = dp_lo[:]

        for bit in range(m):
            if cnt - popcnt[bit] < k:
                up, lo = add(dp_up[bit], dp_lo[bit], 0, a[i])
                if ndp_up[bit] < up or ndp_up[bit] == up and ndp_lo[bit] < lo:
                    ndp_up[bit], ndp_lo[bit] = up, lo
            for j in dests[bit]:
                up, lo = add(dp_up[bit], dp_lo[bit], 0, matrix[i][j])
                if ndp_up[bit | (1 << j)] < up or ndp_up[bit | (1 << j)] == up and ndp_lo[bit | (1 << j)] < lo:
                    ndp_up[bit | (1 << j)], ndp_lo[bit | (1 << j)] = up, lo

        dp_up, dp_lo = ndp_up, ndp_lo

    print(dp_up[-1] * border + dp_lo[-1])


if __name__ == '__main__':
    main()
