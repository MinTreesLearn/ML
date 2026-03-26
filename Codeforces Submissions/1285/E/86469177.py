import io
import os

from collections import Counter, defaultdict, deque

# From: https://github.com/cheran-senthil/PyRival/blob/master/pyrival/data_structures/SegmentTree.py
class SegmentTree:
    def __init__(self, data, default=0, func=max):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size : _size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)


def pack(a, b, c):
    return [a, b, c]
    return (a, b, c)
    return (a << 40) + (b << 20) + c


def unpack(abc):
    return abc
    ab, c = divmod(abc, 1 << 20)
    a, b = divmod(ab, 1 << 20)
    return a, b, c


def merge(x, y):
    # Track numClose, numNonOverlapping, numOpen:
    # e.g., )))) (...)(...)(...) ((((((
    xClose, xFull, xOpen = unpack(x)
    yClose, yFull, yOpen = unpack(y)
    if xOpen == yClose == 0:
        ret = xClose, xFull + yFull, yOpen
    elif xOpen == yClose:
        ret = xClose, xFull + 1 + yFull, yOpen
    elif xOpen > yClose:
        ret = xClose, xFull, xOpen - yClose + yOpen
    elif xOpen < yClose:
        ret = xClose + yClose - xOpen, yFull, yOpen
    # print(x, y, ret)
    return pack(*ret)


def solve(N, intervals):
    endpoints = []
    for i, (l, r) in enumerate(intervals):
        endpoints.append((l, 0, i))
        endpoints.append((r, 1, i))
    endpoints.sort(key=lambda t: t[1])
    endpoints.sort(key=lambda t: t[0])

    # Build the segment tree and track the endpoints of each interval in the segment tree
    data = []
    # Note: defaultdict seems to be faster. Maybe because it traverses in segment tree order rather than randomly?
    idToIndices = defaultdict(list)
    for x, kind, intervalId in endpoints:
        if kind == 0:
            data.append(pack(0, 0, 1))  # '('
        else:
            assert kind == 1
            data.append(pack(1, 0, 0))  # ')'
        idToIndices[intervalId].append(len(data) - 1)
    assert len(data) == 2 * N
    segTree = SegmentTree(data, pack(0, 0, 0), merge)
    # print("init", unpack(segTree.query(0, 2 * N)))

    best = 0
    for intervalId, indices in idToIndices.items():
        # Remove the two endpoints
        i, j = indices
        removed1, removed2 = segTree[i], segTree[j]
        segTree[i], segTree[j] = pack(0, 0, 0), pack(0, 0, 0)

        # Query
        res = unpack(segTree.query(0, 2 * N))
        assert res[0] == 0
        assert res[2] == 0
        best = max(best, res[1])
        # print("after removing", intervals[intervalId], res)

        # Add back the two endpoints
        segTree[i], segTree[j] = removed1, removed2

    return best


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    T = int(input())
    for t in range(T):
        (N,) = [int(x) for x in input().split()]
        intervals = [[int(x) for x in input().split()] for i in range(N)]
        ans = solve(N, intervals)
        print(ans)
