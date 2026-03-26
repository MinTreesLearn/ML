from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n,m=map(int,input().split())
  a=list(map(int,input().split()))
  b=list(map(lambda x:int(x)-1,input().split()))
  ok=[0]*(n-1)
  for i in b:
    ok[i]=1
  while True:
    flag=True
    for i in range(n-1):
      if a[i]>a[i+1]:
        flag=False
        if ok[i]:
          a[i],a[i+1]=a[i+1],a[i]
        else:
          print('NO')
          return
    if flag:
      print('YES')
      return

for _ in range(int(input())):
  solve()