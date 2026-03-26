from collections import defaultdict
import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().strip().split()))
d=defaultdict(int)
mx=max(a)
for i in range(n):
    d[a[i]-i-1]+=a[i]
    mx=max(mx,d[a[i]-i-1])
print(mx)