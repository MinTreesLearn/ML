import bisect
import io
import math
import os
import sys

LO = 'abcdefghijklmnopqrstuvwxyz'
Mod = 1000000007

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# _input = lambda: io.BytesIO(os.read(0, os.fstat(0).st_size)).readline().decode()
_input = lambda: sys.stdin.buffer.readline().strip().decode()

n = int(_input())
s = _input()
z = -1
a = 0
b = 0
for i, x in enumerate(s):
    if x == '(':
        a += 1
    else:
        a -= 1
    if a == 0:
        if x == '(':
            b += i - z
        z = i
print(b if a == 0 else -1)
