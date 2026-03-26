try:
        import sys
        from functools import lru_cache, cmp_to_key
        from heapq import merge, heapify, heappop, heappush
        from math import *
        from collections import defaultdict as dd, deque, Counter as C
        from itertools import combinations as comb, permutations as perm
        from bisect import bisect_left as bl, bisect_right as br, bisect, insort
        from time import perf_counter
        from fractions import Fraction
        import copy
        from copy import deepcopy
        import time
        starttime = time.time()
        mod = int(pow(10, 9) + 7)
        mod2 = 998244353

        def data(): return sys.stdin.readline().strip()
        def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
        def L(): return list(sp())
        def sl(): return list(ssp())
        def sp(): return map(int, data().split())
        def ssp(): return map(str, data().split())
        def l1d(n, val=0): return [val for i in range(n)]
        def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
        def A2(n,m): return [[0]*m for i in range(n)]
        def A(n):return [0]*n
        # sys.setrecursionlimit(int(pow(10,6)))
        # from sys import stdin
        # input = stdin.buffer.readline
        # I = lambda : list(map(int,input().split()))
        # import sys
        # input=sys.stdin.readline
        

        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
except:
        pass
p = []
prime = [1 for i in range(10**5+2)]
for i in range(2,10**5+2):
        if prime[i]==0:
                continue
        p.append(i)
        for j in range(i,10**5+2,i):
                prime[j] = 0



t = 1 
t = L()[0]
for ft in range(t):
        a,m = L()
        
        m = m//gcd(a,m)

        M = m
        divs = dd(int)
        for ele in p:
                while(m%ele==0):
                        divs[ele]+=1
                        m//=ele
                if ele*ele>m:
                        break
        if m!=1:
                divs[m]=1
        ans = Fraction(1)
        for ele in divs:
                if divs[ele]!=0:
                        ele = Fraction(ele)
                        ans*=(1-1/ele)
        
        print(ans*M)

