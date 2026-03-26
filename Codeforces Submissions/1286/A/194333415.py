import bisect
import heapq
import sys
from types import GeneratorType
from functools import cmp_to_key
from collections import defaultdict, Counter, deque
import math
from functools import lru_cache
from heapq import nlargest
from functools import reduce
import random
from operator import mul
inf = float("inf")
PLATFORM = "CF"
if PLATFORM == "LUOGU":
    import numpy as np
    sys.setrecursionlimit(1000000)


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
    n = ac.read_int()
    nums = ac.read_list_ints()
    pre = set(nums)
    cnt = Counter([i%2 for i in range(1, n+1) if i not in pre])

    @ac.bootstrap
    def dfs(i, single, double, pre):
        if (i, single, double, pre) in dct:
            yield
        if i == n:
            dct[(i, single, double, pre)] = 0
            yield
        res = inf
        if nums[i] != 0:
            v = nums[i] % 2
            yield dfs(i+1, single, double, v)
            cur = dct[(i+1, single, double, v)]
            if pre != -1 and pre != v:
                cur += 1
            res = ac.min(res, cur)
        else:
            if single:
                yield dfs(i + 1, single-1, double, 1)
                cur = dct[(i + 1, single-1, double, 1)]
                if pre != -1 and pre != 1:
                    cur += 1
                res = ac.min(res, cur)
            if double:
                yield dfs(i + 1, single, double - 1, 0)
                cur = dct[(i + 1, single, double - 1, 0)]
                if pre != -1 and pre != 0:
                    cur += 1
                res = ac.min(res, cur)
        dct[(i, single, double, pre)] = res
        yield

    dct = dict()
    dfs(0, cnt[1], cnt[0], -1)
    ac.st(dct[(0, cnt[1], cnt[0], -1)])
    return


main()
