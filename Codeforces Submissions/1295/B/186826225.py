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
    n, x = map(int, input().split())
    s = input().strip()
    ans = 0
    curr = 0
    seen_ans = False
    if curr == x:
        ans += 1
        seen_ans = True

    for char in s:
        curr += (char == "0")
        curr -= (char == '1')
        if curr == x:
            seen_ans = True

    diff = curr
    if curr == 0 and seen_ans:
        print(-1)
        continue
    elif curr == 0:
        print(0)
        continue
    # current_balance = x - (y * diff)
    # y * diff = x - current_balance
    # y = (x - current_balance) // diff 

    curr_balance = 0
    for i in range(n):
        curr_balance += (s[i] == "0")
        curr_balance -= (s[i] == '1')
        if (x - curr_balance) % diff == 0 and (x - curr_balance) // diff >= 0:
            # print(i, "chec", (x - curr_balance) // diff)
            ans += 1
    print(ans)