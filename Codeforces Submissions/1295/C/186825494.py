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
    s = input().strip()
    t = input().strip()
    n = len(s)

    seen = [[-1] * 26 for _ in range(n)]
    for i in range(n - 1, -1, -1):
        if i + 1 < n:
            for j in range(26):
                seen[i][j] = seen[i + 1][j]
        seen[i][ord(s[i]) - ord('a')] = i
    
    cur_pos = seen[0][ord(t[i]) - ord('a')]
    if cur_pos == -1:
        print(-1)
        continue
    ans = 1
    for i in range(1, len(t)):
        if cur_pos == n - 1 or seen[cur_pos + 1][ord(t[i]) - ord('a')] == -1:
            cur_pos = seen[0][ord(t[i]) - ord('a')]
            ans += 1
        else:
            cur_pos = seen[cur_pos + 1][ord(t[i]) - ord('a')]

        if cur_pos == -1:
            ans = -1
            break
    print(ans)