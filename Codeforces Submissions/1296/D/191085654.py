from sys import stdin
input=lambda :stdin.readline()[:-1]

n,a,b,k=map(int,input().split())
h=list(map(int,input().split()))
ans=0
c=[]
for i in h:
  r=i%(a+b)
  if 0<r<=a:
    ans+=1
    continue
  if r==0:
    r+=a+b
  c.append((r+a-1)//a-1)

c.sort()
for i in c:
  if k>=i:
    ans+=1
    k-=i
print(ans)