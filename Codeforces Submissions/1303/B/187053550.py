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
    
    n, g, b = map(int, input().split())
    
    def poss(num):
        want = (n // 2) + (n & 1)
        full_cycles = num // (g + b)
        remaining_good = min(g, num % (g + b))
        remaining_bad = max(0, num % (g + b) - remaining_good)
        want -= (full_cycles * g + remaining_good)
        remain = 0
        if want < 0:
            remain = -want
            want = 0
        bad_want = n - ((n // 2) + (n & 1))
        bad_want -= remain
        return want == 0 and (full_cycles * b + remaining_bad) >= bad_want

    l = 1; r = 10**18
    best = -1

    while l <= r:
        mid = (l + r) // 2
        if poss(mid):
            r = mid - 1
            best = mid
        else:
            l = mid + 1
    print(best)