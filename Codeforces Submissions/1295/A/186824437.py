from collections import Counter, deque, defaultdict
import math
from itertools import permutations, accumulate
from sys import *
from heapq import *
from bisect import bisect_left, bisect_right
from functools import cmp_to_key
from random import randint
xor = randint(10 ** 7, 10**8)
# https://docs.python.org/3/library/bisect.html
on = lambda mask, pos: (mask & (1 << pos)) > 0
lcm = lambda x, y: (x * y) // math.gcd(x,y)
rotate = lambda seq, k: seq[k:] + seq[:k] # O(n)
input = stdin.readline
'''
Check for typos before submit, Check if u can get hacked with Dict (use xor)
Observations/Notes: 
'''
for _ in range(int(input())):
    n = int(input())
    ans = []
    while n >= 2:
        ans.append("1")
        n -= 2
    if n == 1:
        ans.pop()
        ans.append("7")
        ans = ans[::-1]
    print("".join(ans))