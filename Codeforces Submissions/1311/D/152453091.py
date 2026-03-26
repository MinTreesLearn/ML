import sys
input = lambda: sys.stdin.readline().rstrip('\n\r')

from collections import Counter, defaultdict, deque
from itertools import accumulate, chain, zip_longest, product, repeat
from bisect import bisect_left, bisect_right
from math import gcd
from string import ascii_lowercase
from functools import cmp_to_key

mod = 10 ** 9 + 7
mod_2 = 998244353

def sieve(limit = 10 ** 6):
    """
    Input: limit : Integer
    Output: arr : List[Integer]
    
    Returns a list of (limit) integers, and the following holds

    arr[0] = -1
    arr[1] = -1
    arr[prime] = prime
    arr[non-prime] = prime-factor

    Complexity : O(limit)
    """
    arr = [-1 for _ in range(limit)]
    for i in range(2, limit, 2):
        arr[i] = 2
    for i in range(3, limit, 2):
        if arr[i] != -1:
            continue
        arr[i] = i
        for j in range(i * i, limit, 2 * i):
            arr[j] = i
    return arr

def factor_list_fast(limit = 10 ** 6, sort = True):
    """
    Input:  limit   : Integer
            sort    : Boolean
    Output: arr     : List[List[Integer]]
    
    Dependencies: Sieve of Eratosthenes

    Returns a list of (limit) lists, and the following holds

    arr[0] = []
    arr[1] = [1]
    arr[i] = [Distinct Factors of the Number i]
    if sort is True then arr[i] is sorted
    
    Complexity :    Only God knows that. What I know is that 
                    it is sufficiently fast
    """
    arr = [[] for _ in range(limit)]
    arr[1] = [1]
    s = sieve(limit)
    for i in range(2, limit):
        prime_factor, c, n = s[i], 0, i
        for _ in range(i + 1):
            if n % prime_factor == 0:
                c += 1
                n //= prime_factor
            else:
                break
        arr[i] = arr[n][:]
        mul = 1
        for _ in range(1, c + 1):
            mul *= prime_factor
            for val in arr[n]:
                arr[i].append(val * mul)
    if sort:
        for idx, val in enumerate(arr):
            arr[idx].sort()
    return arr

fl = factor_list_fast(20010)

def solve():
    a, b, c = map(int, input().split())
    Af, Bf, Cf = b, b, b
    cost = abs(a - Af) + abs(b - Bf) + abs(c - Cf) 
    for B in range(max(1, b - cost), min(b + cost + 1, 20010)):
        cC1 = c % B
        cC2 = B - (c % B)
        if cC1 < cC2 and c != cC1:
            C = c - cC1
        else:
            C = c + cC2
        f = fl[B]
        iA1 = bisect_right(f, a)
        iA2 = iA1 - 1
        if 0 <= iA1 < len(f):
            A = f[iA1]
            nc = abs(a - A) + abs(b - B) + abs(c - C)
            if nc < cost:
                cost = nc
                Af, Bf, Cf = A, B, C
        if 0 <= iA2 < len(f):
            A = f[iA2]
            nc = abs(a - A) + abs(b - B) + abs(c - C)
            if nc < cost:
                Af, Bf, Cf = A, B, C
                cost = nc
    return "%d\n%d %d %d" % (cost, Af, Bf, Cf)

for _ in range(int(input())):
    val = solve()
    print(val)

