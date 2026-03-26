import sys
input=sys.stdin.buffer.readline
n,m,p=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
idx1=-1
idx2=-1
for i in range(n):
  if a[i]%p!=0:
    idx1=i
    break
for i in range(m):
  if b[i]%p!=0:
    idx2=i
    break
print(idx1+idx2)