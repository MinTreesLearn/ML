import sys
input = sys.stdin.buffer.readline 

class SegmentTree:
    def __init__(self, data, default=float('inf'), func=min):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
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
    
    
def operation(S, x):
    my_min = S.query(0, x)
    if S[0]==my_min:
        return my_min*x
    else:
        s = 0
        e = x
        while s+1 < e:
            m = (s+e)//2
            if S.query(0, m+1) > my_min:
                s, e = m, e
            else:
                s, e = s, m
        return my_min*x+e
    
def process(A, x):
    n = len(A)
    d = [0 for i in range(x)]
    S = SegmentTree(data=d)
    for i in range(n):
        ai = A[i]
        S[ai % x]+=1
        entry = operation(S, x)
        sys.stdout.write(f'{entry}\n')
   
    return

n, x = [int(x) for x in input().split()]
A = []
for i in range(n):
    ai = int(input())
    A.append(ai)
process(A, x)
    