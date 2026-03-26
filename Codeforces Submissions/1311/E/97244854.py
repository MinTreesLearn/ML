import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    t = int(input())
    for _ in range(t):
        n, d = map(int, input().split())
        depth = [0] + list(range(n))
        child = [0] + [1] * (n - 1) + [0]
        par = [-1, -1] + list(range(1, n))
        cur_d = sum(depth)

        if d > cur_d:
            print('NO')
            continue

        for i in range(n, 0, -1):
            if child[i]:
                continue
            child[par[i]] -= 1
            p, delta = -1, 0

            for j in range(1, n + 1):
                if i != j and child[j] < 2 and cur_d - d >= depth[i] - depth[j] - 1 and depth[i] - depth[j] - 1 > delta:
                    delta = depth[i] - depth[j] - 1
                    p = j
            if p != -1:
                child[p] += 1
                par[i] = p
                depth[i] = depth[p] + 1
                cur_d -= delta
            else:
                break

        if cur_d == d:
            print('YES')
            print(*par[2:])
        else:
            print('NO')


if __name__ == '__main__':
    main()
