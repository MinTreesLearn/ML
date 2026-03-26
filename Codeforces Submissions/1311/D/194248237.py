import bisect
import heapq
import sys
from types import GeneratorType
from functools import cmp_to_key
from collections import defaultdict, Counter, deque
import math
from functools import lru_cache
from heapq import nlargest
import random
inf = float("inf")
# sys.setrecursionlimit(1000000)


class FastIO:
    def __init__(self):
        return

    @staticmethod
    def _read():
        return sys.stdin.readline().strip()

    def read_int(self):
        return int(self._read())

    def read_float(self):
        return float(self._read())

    def read_ints(self):
        return map(int, self._read().split())

    def read_floats(self):
        return map(float, self._read().split())

    def read_ints_minus_one(self):
        return map(lambda x: int(x) - 1, self._read().split())

    def read_list_ints(self):
        return list(map(int, self._read().split()))

    def read_list_floats(self):
        return list(map(float, self._read().split()))

    def read_list_ints_minus_one(self):
        return list(map(lambda x: int(x) - 1, self._read().split()))

    def read_str(self):
        return self._read()

    def read_list_strs(self):
        return self._read().split()

    def read_list_str(self):
        return list(self._read())

    @staticmethod
    def st(x):
        return sys.stdout.write(str(x) + '\n')

    @staticmethod
    def lst(x):
        return sys.stdout.write(" ".join(str(w) for w in x) + '\n')

    @staticmethod
    def round_5(f):
        res = int(f)
        if f - res >= 0.5:
            res += 1
        return res

    @staticmethod
    def max(a, b):
        return a if a > b else b

    @staticmethod
    def min(a, b):
        return a if a < b else b

    @staticmethod
    def bootstrap(f, queue=[]):
        def wrappedfunc(*args, **kwargs):
            if queue:
                return f(*args, **kwargs)
            else:
                to = f(*args, **kwargs)
                while True:
                    if isinstance(to, GeneratorType):
                        queue.append(to)
                        to = next(to)
                    else:
                        queue.pop()
                        if not queue:
                            break
                        to = queue[-1].send(to)
                return to
        return wrappedfunc


def main(ac=FastIO()):
    for _ in range(ac.read_int()):
        a, b, c = ac.read_list_ints()
        ans = inf
        res = []
        for x in range(1, 2*a+1):
            for y in range(x, 2*b+1, x):
                if y%x == 0:
                    for z in [(c//y)*y, (c//y)*y+y]:
                        cost = abs(a-x)+abs(b-y)+abs(c-z)
                        if cost < ans:
                            ans = cost
                            res = [x, y, z]
        ac.st(ans)
        ac.lst(res)
    return


main()
