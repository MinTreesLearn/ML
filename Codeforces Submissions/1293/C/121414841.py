from sys import stdin, stdout
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
        
mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x%y else 0
def ceil(a,b): return (a+b-1)//b
S1 = 'abcdefghijklmnopqrstuvwxyz'
S2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 
n, q = mp()
md = dd(int)
ml = l2d(2, n)
prev = dd(int)
s = set()
for i in range(q):
    x, y = mp()
    x -= 1
    y -= 1
    if ml[x][y]:
        ml[x][y] = 0
        if x:
            if y>0: 
                if (y-1, y) in s: s.remove((y-1, y))
            if y<n-1: 
                if (y+1, y) in s: s.remove((y+1, y))
        else:
            if y>0: 
                if (y, y-1) in s: s.remove((y, y-1))
            if y<n-1: 
                if (y, y+1) in s: s.remove((y, y+1))
        if (y, y) in s: s.remove((y, y))
    else:
        ml[x][y] = 1
        if x:
            if y>0: 
                if ml[0][y-1]: s.add((y-1, y))
            if y<n-1: 
                if ml[0][y+1]: s.add((y+1, y))
        else:
            if y>0: 
                if ml[1][y-1]: s.add((y, y-1))
            if y<n-1: 
                if ml[1][y+1]: s.add((y, y+1))
        if ml[1-x][y]: s.add((y, y))
    print("No" if len(s) else "Yes")
    
    
