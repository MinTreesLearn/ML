
class LazySegmentTree: # add operations, max queries
    def __init__(self, data, func=max):
        """initialize the lazy segment tree with data"""
        self._func = func

        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
        self._lazy = [0] * (2 * _size)

        self.data = [-int(2e9 - 5)] * (2 * _size) # TO CHANGE FOR MIN
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = self._func(self.data[i + i], self.data[i + i + 1])

    def __len__(self):
        return self._len

    def _push(self, idx):
        """push query on idx to its children"""
        # Let the children know of the queries
        q, self._lazy[idx] = self._lazy[idx], 0
        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q
        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q

    def _update(self, idx):
        """updates the node idx to know of all queries applied to it via its ancestors"""
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)

    def _build(self, idx):
        """make the changes to idx be known to its ancestors"""
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1

    def add(self, start, stop, value):
        """lazily add value to [start, stop]"""
        stop += 1
        start = start_copy = start + self._size
        stop = stop_copy = stop + self._size
        while start < stop:
            if start & 1:
                self._lazy[start] += value
                self.data[start] += value
                start += 1
            if stop & 1:
                stop -= 1
                self._lazy[stop] += value
                self.data[stop] += value
            start >>= 1
            stop >>= 1

        # Tell all nodes above of the updated area of the updates
        self._build(start_copy)
        self._build(stop_copy - 1)

    def query(self, start, stop):
        """func of data[start, stop]"""
        stop += 1
        start += self._size
        stop += self._size

        # Apply all the lazily stored queries
        self._update(start)
        self._update(stop - 1)

        res = -int(2e9) # TO CHANGE FOR MIN
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "LazySegmentTree({0})".format(self.data)

def main():
    
    n, m, p = readIntArr()
    aca = [] # weapons
    for _ in range(n):
        a, ca = readIntArr()
        aca.append((a, ca))
    bcb = [] # armor
    for _ in range(m):
        b, cb = readIntArr()
        bcb.append((b, cb))
    yxz = [] # monsters
    for _ in range(p):
        x, y, z = readIntArr()
        yxz.append((y, x, z))
    
    aca.sort(key = lambda x : x[0]) # sort by a asc
    segArr = [-ca for a, ca in aca]
    lst = LazySegmentTree(segArr)
    
    bcb.sort(key = lambda x : x[0]) # sort by b asc
    yxz.sort(key = lambda x : x[0]) # sort by y asc
    
    ans = -2e9 - 5
    i = 0
    for b, cb in bcb: # identify killable monsters with y < b, and update the seg tree
        while i < p and yxz[i][0] < b:
            y, x, z = yxz[i]
            # binary search for j where aca[j][0] > x
            lo = -1; hi = n - 1
            while lo < hi:
                mid = (lo + hi + 1) // 2
                if aca[mid][0] <= x:
                    lo = mid
                else:
                    hi = mid - 1
            j = lo + 1
            if j < n:
                lst.add(j, n - 1, z)
            i += 1
        ans = max(ans, -cb + lst.query(0, n - 1))
    print(ans)
    
    return



import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(a, b, c):
    print('? {} {} {}'.format(a, b, c))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ansArr):
    print('! {}'.format(' '.join([str(x) for x in ansArr])))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353

from math import gcd,floor,ceil
import math
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()