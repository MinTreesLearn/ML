import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from bisect import insort
from collections import Counter
from collections import deque
from heapq import heappush,heappop,heapify
from itertools import permutations,combinations
mod = int(1e9)+7
 
 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x : stdout.write(str(x)+"\n")


t = ip()
for _ in range(t):
    n,m,k = inp()
    arr = list(inp())
    if m-1<=k:
        ans = max(arr[:m])
        ans = max(ans,max(arr[n-m:n]))
    else:
        rem = m-1-k
        an = []
        org = deque(arr)
        elelist = deque()
        outer = []
        for i in range(k):
            elelist.append(org.pop())
        for i in range(k+1):
            if i == 0:
                pass
            else:
                org.append(elelist.pop())
                org.popleft()
            ch = deque(org)
            inner = []
            empty = deque()
            for i in range(rem):
                empty.append(ch.pop())
            for i in range(rem+1):
                if i == 0:
                    pass
                else:
                    ch.append(empty.pop())
                    ch.popleft()
                inner.append(max(ch[0],ch[-1]))
            outer.append(min(inner))
        ans = max(outer)
    out(ans)
            
                    
                
                
            
