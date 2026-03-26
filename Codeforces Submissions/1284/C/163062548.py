
#  If you win, you live. You cannot win unless you fight.
from sys import  stdin
input=stdin.readline
import heapq
import string
rd=lambda: map(lambda s: int(s), input().strip().split())
ri=lambda: int(input())
rs=lambda :input().strip()
from collections import defaultdict,deque,Counter
from bisect import bisect_left as bl, bisect_right as br
from random import randint
from math import gcd, ceil, floor,log2,factorial
random = randint(1, 10 ** 9)
mod=10**9+7
class wrapper(int):
    def __hash__(self):
        return super(wrapper, self).__hash__() ^ random

#similar to last contest C
n,m=rd()
mod=m
fac=[0]*(n+2)
fac[1]=1
for i in range(2,n+1):
    fac[i]=(i*fac[i-1])%(mod)
ans=0
for i in range(1,n+1):
    r=n
    l=i
    ans+=(r-l+1)*((fac[r-l+1]*(fac[l]))%mod)
    ans%=mod
print(ans)
