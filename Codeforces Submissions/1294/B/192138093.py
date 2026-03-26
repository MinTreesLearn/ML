from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n=int(input())
  xy=[]
  for i in range(n):
    x,y=map(int,input().split())
    xy.append((x,y))
  xy.sort()
  nowx,nowy=0,0
  ans=[]
  for x,y in xy:
    if nowx>x or nowy>y:
      print('NO')
      return
    while nowx<x:
      ans.append('R')
      nowx+=1
    while nowy<y:
      ans.append('U')
      nowy+=1
  print('YES')
  print(*ans,sep='')


for _ in range(int(input())):
  solve()