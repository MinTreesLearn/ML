from math import comb
n,m=map(int,input().split())
print(comb(n+2*m-1,2*m)%(10**9+7))