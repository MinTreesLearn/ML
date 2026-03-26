##############################
#       author: oneku        #
#  trying to solve problems  #
##############################

# Bismillah


import sys
import os
from functools import reduce
from io import BytesIO, IOBase
from typing import List
from bisect import bisect, bisect_left, bisect_right

# from typing import List


BUFFER_SIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFER_SIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, **kwargs):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFER_SIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin = IOWrapper(sys.stdin)
sys.stdout = IOWrapper(sys.stdout)
fast_input = lambda: sys.stdin.readline().rstrip("\r\n")

read_int = lambda: int(fast_input())
read_ints = lambda: map(int, fast_input().split())
read_list_int = lambda: list(map(int, fast_input().split()))
read_str = lambda: str(fast_input())
read_strs = lambda: map(str, fast_input().split())
read_list_str = lambda: list(map(str, fast_input().split()))

output = lambda *value: sys.stdout.write(' '.join(map(str, value)) + '\n')

MOD = 32_768

'''
   
'''

MOD = 10 ** 9 + 7


def solve() -> None:
    n = read_int()
    nums = sorted(read_list_int(), reverse=True)

    output(*nums)
    return


'''
    5 3 2 3 5

'''


def main() -> None:
    # solve()
    for _ in range(read_int()):
        solve()


if __name__ == '__main__':
    main()
