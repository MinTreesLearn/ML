from collections import defaultdict, deque, Counter
from sys import stdin, stdout
from heapq import heappush, heappop
import math
import io
import os
import math
import bisect

#?############################################################


def isPrime(x):
    for i in range(2, x):
        if i*i > x:
            break
        if (x % i == 0):
            return False
    return True

#?############################################################


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p


#?############################################################

def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            l.append(i)
            n = n // i
    if n > 2:
        l.append(n)
    return l


#?############################################################

def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

#?############################################################


def sieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime


#?############################################################

def digits(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c

#?############################################################


def ceil(n, x):
    if (n % x == 0):
        return n//x
    return n//x+1

#?############################################################


def mapin():
    return map(int, input().split())

#?############################################################


input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
# python3 15.py<in>op



    

def solve(l, n, m, c, d):

    s = [0]*n
    for i in range(n):
        if(l[i]%m == c):
            a = l[i]//m
            a-=d
            if(a>= n):
                continue
                
            if(a-i>=0):
                a = (i+n-a)%n
            else:
                a = (i-a)%n
            # print(i, l[i], n, m, a)
            if(a<n):
                s[a]+=1
            
    ans = 1e9
    for i in range(n):
        temp = n
        temp-=s[i]
        temp+=i
        # print(i, temp)
        ans =min(ans, temp)
    
    # print(s, ans)
    return ans
        






n, m = mapin()
sa = []
for i in range(m):
    sa.append([0]*n)
for i in range(n):
    tt = [int(x) for x in input().split()]
    for j in range(m):
        sa[j][i] = tt[j]
        
        
ans = 0
for j in range(m):
    a =solve(sa[j], n, m, (j+1)%m, (j+1)//m)
    ans+=a
    # print(j, a)
# a = a =solve(sa[-1], n, m, m)
        
print(ans)
    