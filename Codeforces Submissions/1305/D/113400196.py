import sys
import math
import heapq
import bisect
from collections import Counter
from collections import defaultdict
from io import BytesIO, IOBase
import string


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
        self.BUFSIZE = 8192

    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


def get_int():
    return int(input())


def get_ints():
    return list(map(int, input().split(' ')))


def get_int_grid(n):
    return [get_ints() for _ in range(n)]


def get_str():
    return input().strip()


def get_strs():
    return get_str().split(' ')


def flat_list(arr):
    return [item for subarr in arr for item in subarr]


def yes_no(b):
    if b:
        return "YES"
    else:
        return "NO"


def binary_search(good, left, right, delta=1, right_true=False):
    """
    Performs binary search
    ----------
    Parameters
    ----------
    :param good: Function used to perform the binary search
    :param left: Starting value of left limit
    :param right: Starting value of the right limit
    :param delta: Margin of error, defaults value of 1 for integer binary search
    :param right_true: Boolean, for whether the right limit is the true invariant
    :return: Returns the most extremal value interval [left, right] which is good function evaluates to True,
            alternatively returns False if no such value found
    """

    limits = [left, right]
    while limits[1] - limits[0] > delta:
        if delta == 1:
            mid = sum(limits) // 2
        else:
            mid = sum(limits) / 2
        if good(mid):
            limits[int(right_true)] = mid
        else:
            limits[int(~right_true)] = mid
    if good(limits[int(right_true)]):
        return limits[int(right_true)]
    else:
        return False


def prefix_sums(a):
    p = [0]
    for x in a:
        p.append(p[-1] + x)
    return p


def solve_a():
    n = int(input())
    a = [int(s) for s in input().split(' ')]
    b = [int(s) for s in input().split(' ')]
    a.sort()
    b.sort()
    return ' '.join([str(i) for i in a]), ' '.join([str(j) for j in b])


def get_tree(n):
    T = defaultdict(set)
    for _ in range(n - 1):
        a, b = get_ints()
        T[a].add(b)
        T[b].add(a)
    return T


def solve_d():
    n = get_int()
    T = get_tree(n)
    leafs = [u for u in range(1, n + 1) if len(T[u]) == 1]

    def query(a, b):
        print('?', a, b)
        sys.stdout.flush()
        return get_int()

    def guess(a):
        print('!', a)
        return

    while leafs:
        a, b = leafs.pop(), leafs.pop()
        r = query(a, b)
        if r == a:
            guess(a)
            return
        elif r == b:
            guess(b)
            return
        else:
            c = T[a].pop()
            d = T[b].pop()
            T[c].remove(a)
            T[d].remove(b)
            if len(T[c]) == 1:
                leafs.append(c)
            if len(T[d]) == 1 and c != d:
                leafs.append(d)
            if len(T[c]) == 0:
                lonely = c
            elif len(T[d]) == 0:
                lonely = d
    guess(lonely)


solve_d()
