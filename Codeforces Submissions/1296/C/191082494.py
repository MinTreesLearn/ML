from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n=int(input())
  s=input()
  x,y=0,0
  ans=[10**9,-1,-1]
  seen=dict()
  seen[(x,y)]=0
  for i in range(n):
    if s[i]=='L':
      x-=1
    elif s[i]=='R':
      x+=1
    elif s[i]=='U':
      y+=1
    else:
      y-=1
    if (x,y) in seen:
      j=seen[(x,y)]
      if i-j<ans[0]:
        ans=[i-j,j,i]
    seen[(x,y)]=i+1
  if ans[0]==10**9:
    print(-1)
  else:
    print(ans[1]+1,ans[2]+1)




for _ in range(int(input())):
  solve()