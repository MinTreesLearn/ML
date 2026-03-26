import sys
from math import *
from collections import defaultdict
inp = lambda: sys.stdin.buffer.readline().decode().strip()
out=sys.stdout.write
# n=int(inp())
# arr=list(map(int,inp().split()))
n,m=map(int,inp().split())
mod= 998244353
fact=[1]*(m+1)
for i in range(1,m+1):
    fact[i]=(fact[i-1]*i)%mod
def modi(x,pri1):
    return fast_exp(x,pri1-2,pri1)
def ncr(n,r,pri1):
    return ((fact[n]*modi(fact[r],pri1))%pri1)*((modi(fact[n-r],pri1))%pri1)%pri1
def fast_exp(x,n,mod):
    ans=1
    while n>0:
        if n%2==1:
            ans=(ans*x)%mod
            n-=1
        x=(x*x)%mod
        n //= 2
    return ans
ans=ncr(m,n-1,mod)*(n-2)*fast_exp(2,n-3,mod)
ans%=mod
print(ans)