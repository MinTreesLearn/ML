#OMM NAMH SHIVAY
#JAI SHREE RAM
import sys,math,heapq,queue
from functools import cmp_to_key
fast_input=sys.stdin.readline 
for _ in range(int(fast_input())):
    n,m=map(int,fast_input().split()) 
    zero=n-m 
    equal=zero//(m+1)
    rem=zero%(m+1)
    ans=n*(n+1)//2 
    ans-=rem*(equal+1)*(equal+2)//2 
    ans-=(m+1-rem)*(equal)*(equal+1)//2 
    print(ans)
    