import copy
import random
import heapq
import math
import sys
import bisect
import datetime
from functools import lru_cache
from collections import deque
from collections import Counter
from collections import defaultdict
from itertools import combinations
from itertools import permutations
from types import GeneratorType
from functools import cmp_to_key
from functools import reduce
from operator import xor
from operator import mul
from operator import add
from decimal import Decimal
from heapq import nlargest

inf = float("inf")


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
    def bootstrap(f, stack=[]):
        def wrappedfunc(*args, **kwargs):
            if stack:
                return f(*args, **kwargs)
            else:
                to = f(*args, **kwargs)
                while True:
                    if isinstance(to, GeneratorType):
                        stack.append(to)
                        to = next(to)
                    else:
                        stack.pop()
                        if not stack:
                            break
                        to = stack[-1].send(to)
                return to

        return wrappedfunc


def main(ac=FastIO()):
    n = ac.read_int()
    a = ac.read_list_ints()
    t = ac.read_list_ints()
    lst = [[a[i], t[i]] for i in range(n)]
    del a
    del t
    lst.sort(key=lambda it: [it[0], -it[1]])
    stack = []
    total = ans = 0
    cur = -1
    i = 0
    while i < n or stack:
        if not stack:
            cur = lst[i][0]
        while i < n and lst[i][0] == cur:
            heapq.heappush(stack, -lst[i][1])
            total += lst[i][1]
            i += 1
        total += heapq.heappop(stack)
        ans += total
        cur += 1
    ac.st(ans)
    return


main()
