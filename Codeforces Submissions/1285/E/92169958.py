import io
import os
from collections import defaultdict


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


class Node:
    def __init__(self, numClose, count, numOpen):
        self.close = numClose
        self.count = count
        self.open = numOpen


neutral = Node(0, 0, 0)


def combine(x, y):
    # Track numClose, numCount, numOpen:
    # e.g., )))) (...)(...)(...) ((((((
    if x.open == y.close == 0:
        ret = x.close, x.count + y.count, y.open
    elif x.open == y.close:
        ret = x.close, x.count + 1 + y.count, y.open
    elif x.open > y.close:
        ret = x.close, x.count, x.open - y.close + y.open
    elif x.open < y.close:
        ret = x.close + y.close - x.open, y.count, y.open
    return Node(*ret)


def solve(N, intervals):
    OPEN = 0
    CLOSE = 1
    endpoints = []
    for i, (l, r) in enumerate(intervals):
        endpoints.append((l, OPEN, i))
        endpoints.append((r, CLOSE, i))
    endpoints.sort(key=lambda t: t[1])
    endpoints.sort(key=lambda t: t[0])

    # Build the segment tree and track the endpoints of each interval in the segment tree
    data = []
    idToIndices = defaultdict(list)
    for x, kind, intervalId in endpoints:
        if kind == OPEN:
            data.append(Node(0, 0, 1))
        else:
            assert kind == CLOSE
            data.append(Node(1, 0, 0))
        idToIndices[intervalId].append(len(data) - 1)
    assert len(data) == 2 * N

    segTree = SegmentTree(data, Node(0, 0, 0), combine)

    best = 0
    for intervalId, indices in idToIndices.items():
        # Remove the two endpoints
        i, j = indices
        removed1, removed2 = segTree[i], segTree[j]
        segTree[i], segTree[j] = neutral, neutral

        # Query
        res = segTree.query(0, 2 * N)
        assert res.open == 0
        assert res.close == 0
        best = max(best, res.count)

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
