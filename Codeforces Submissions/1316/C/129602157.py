
import sys
input=sys.stdin.readline
n,m,p = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

Pa = [A[i]%p==0 for i in range(n)]
Pb = [B[i]%p==0 for i in range(m)]
for i in range(n):
    if not Pa[i]:
        x=i
        break
for i in range(m):
    if not Pb[i]:
        y=i
        break
print(x+y)