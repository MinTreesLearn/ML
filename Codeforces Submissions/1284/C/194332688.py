# Thank God that I'm not you.
from itertools import permutations, combinations;
import heapq;
from collections import Counter, deque;
import math;
import sys;
from functools import lru_cache;






n, mod = map(int, input().split())


factorials = [1]

currMul = 1;
for i in range(1, n + 1):
    currMul *= i;
    currMul %= mod;
    factorials.append(currMul);


ans = 0;

sub = 0;
currN = n;
for i in range(1, n + 1):
    ans += ((currN) * factorials[n - i] * factorials[i] * (currN));
    currN -= 1;
    ans %= mod;

print(ans)



