from math import *
from collections import *
import os
from io import BytesIO, IOBase
import sys
from bisect import *
from heapq import *
 
MOD = 1000000007


# Code by Big Dick Daddy Dick
 
def binpow(a, b, m):
    a %= m
    x = 1
    while b > 0:
        if b & 1:
            x = x * a % m
        a = a * a % m
        b >>= 1
    return x

 
 
def binser(arr, l, r, x):
    while l < r:
        mid = l + (r - l) // 2
        # print(l, r, mid)
 
        if arr[mid] == x:
            return mid
 
        elif arr[mid] < x:
            l = mid + 1
 
        else:
            r = mid - 1
 
    return mid
 
def lcm(a, b):
    return (a * b) // gcd(a, b)
 
def sod(n):
    l = list(str(n))
    s = 0
    for i in l:
        s += int(i)
    return s
 
 
def prime_factors(num):   
    l =[]
    if num % 2:
        l.append(2)
    while num % 2 == 0:  
        num = num / 2  
  
    for i in range(3, int(sqrt(num)) + 1, 2):  
        if not num % i:
            l.append(i)
        while num % i == 0:  
            num = num / i
    if num > 2:
        l.append(num)
    return l
 
 
def factmod(n, p):
 
    f = defaultdict(int)
    f[0] = 1
    for i in range(1, n + 1):
        f[i] = (f[i-1] * i) % MOD
 
    """
    res = 1
    while (n > 1):
        if (n//p) % 2:
            res = p - res
 
        res = res * f[n%p] % p
        n //= p
    """
 
    return f
 
 
 
def largestPower(n, p):
     
    # Initialize result
    x = 0
     
    # Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n):
        n //= p
        x += n
    return x
 
def modFact(n, p) :
 
    if (n >= p) :
        return 0
 
    res = 1
    isPrime = [1] * (n + 1)
    i = 2
    while(i * i <= n):
        if (isPrime[i]):
            for j in range(2 * i, n, i) :
                isPrime[j] = 0
        i += 1
         
    # Consider all primes found by Sieve
    for i in range(2, n):
        if (isPrime[i]) :
             
            k = largestPower(n, i)
 
            # Multiply result with (i^k) % p
            res = (res * binpow(i, k, p)) % p
 
    return res
 
def drec(x, y):
    if y == x + 1:
        return 'R'
    if y == x - 1:
        return 'L'
    if x < y:
        return 'D'
    return 'U'
 
def cellhash(x, y):
    return (x - 1) * m + y
 

 
def bfs(src, dest):
    q = deque([src])
    vis[src] = True
 
    while q:
        i = q.popleft()
        if i == dest:
            return True
        for j in ajl[i]:
            if not vis[j]:
                vis[j] = True
                q.append(j)
    return False
 
def bins(l, x, n):
    i = bisect_left(l, x)
    if i < n:
        return i
    if i:
        return (i-1)
    else:
        return n

def cond(l):
    for i in range(len(l) - 1):
        if l[i] == str(int(l[i + 1]) - 1):
            return False
    return True

def isvowel(s):
    if s in list("aeiou"):
        return 1
    return 0

def countOdd(L, R):
 
    N = (R - L) // 2
 
    # if either R or L is odd
    if (R % 2 != 0 or L % 2 != 0):
        N += 1
 
    return N

def tst(A, B, C):
    return ((A|B) & (B|C) & (C|A))

def palcheck(n, s):
    i, j = 0, n - 1
    while i <= j:
        if s[i] == s[j]:
            return False
        i += 1
        j -= 1
    return True

def sakurajima(n):
    if n < 9:
        n = 10
    l = [1] * (n + 1)
    l[1] = 0

    for i in range(2, int(n ** 0.5) + 1):
        if l[i]:
            for j in range(i * i, n + 1, i):
                if not j % i:
                    l[j] = 0
    return l

def prchck(n):
    l = [1] * (n + 1)
    l[1] = 0
    for i in range(2, n + 1):
        for j in range(2, int(sqrt(n)) + 1):
            if j % i == 0:
                l[j] = 1
    return l

def ispal(s, n):
    for i in range(n // 2):
        if s[i] != s[n - i - 1]:
            return False
    return True

def dfs(i, tmp, vis):
    vis[i] = True
    if i == int(i):
        for j in range(cnt[i]):
            tmp.append(i)

    for j in ajl[i]:
        if not vis[j]:
            tmp = dfs(j, tmp, vis)

    return tmp


def panda(n, s):
	x, y = '0', '0'
	ans = []
	ls, li = [], []
	m = 0
	cnt = 1

	for i in range(n):
		for j in range(m):
			if s[i] >= ls[j]:
				ans.append(li[j])
				ls[j] = s[i]
				break
		else:
			li.append(cnt)
			ans.append(cnt)
			ls.append(s[i])
			cnt += 1
			m += 1

	# print(li, ls)
	print(cnt - 1)
	return ans
    

# Code by Big Dick Daddy Dick

# n = int(input())
# n, k = map(int, input().split())
# s = input()
# l = list(map(int, input().split()))
# memo = [[-1 for i in range(n + 1)] for j in range(2)]

input = sys.stdin.readline


t = 1
# t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print(*panda(n, s))


    # print("Case #" + str(_ + 1) + ": " + str(ans))