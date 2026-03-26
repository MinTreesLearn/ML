# Thank God that I'm not you.
from itertools import permutations, combinations;
import heapq;
from collections import Counter, deque;
import math;
import sys;






mod = 10**9 + 7;



factorials = [1]

currMul = 1;
for i in range(1, 10**5 + 5):
    currMul *= i;
    currMul %= mod;
    factorials.append(currMul);



def nCR(n, r):
    numerator = factorials[n]
    denominator = (factorials[r] * factorials[n - r]) % mod;
    return (numerator * pow(denominator, mod - 2, mod)) % mod;



n, m = map(int, input().split())


print(nCR(((n - 1) + (2 * m)), n - 1) % mod)