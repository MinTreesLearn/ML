from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n,m=map(int,input().split())
  s=input()
  p=list(map(lambda x:int(x)-1,input().split()))
  cnt=[0]*n
  for i in p:
    cnt[i]+=1
  tmp=1
  ans=[0]*26
  for i in range(n-1,-1,-1):
    tmp+=cnt[i]
    ans[ord(s[i])-97]+=tmp
  print(*ans)

for _ in range(int(input())):
  solve()