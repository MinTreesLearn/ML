from sys import stdin
input=lambda :stdin.readline()[:-1]

def fact(n):
  res=n
  a=[]
  i=2
  while i*i<=res:
    if res%i==0:
      cnt=0
      while res%i==0:
        cnt+=1
        res//=i
      a.append((i,cnt))
    i+=1
  if res!=1:
    a.append((res,1))
  return a

import math
def solve():
  x,m=map(int,input().split())
  g=math.gcd(x,m)
  m//=g
  ans=m
  for p,_ in fact(m):
    ans=ans//p*(p-1)
  print(ans)

for _ in range(int(input())):
  solve()