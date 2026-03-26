from sys import stdin
input=lambda :stdin.readline()[:-1]

memo=set()
def f(n,m,d):
  if (n,m,d) in memo:
    return [-1]
  memo.add((n,m,d))
  for i in range(1,2*m+1):
    n2=n-i
    d2=d-n
    if n2>=0 and d2>=0:
      if n2==0 and d2==0:
        return [i]
      res=f(n2,i,d2)
      if res[0]!=-1:
        return res+[i]
  return [-1]

def solve():
  memo.clear()
  n,d=map(int,input().split())
  ans=f(n-1,1,d)
  if ans[0]==-1:
    print('NO')
    return
  print('YES')
  ans=ans[::-1]
  tmp=0
  ANS=[0]*(n-1)
  par=[[] for i in range(n)]
  for i in range(n-1):
    if ans[tmp]==0:
      tmp+=1
    ans[tmp]-=1
    if tmp==0:
      ANS[i]=1
    else:
      ANS[i]=par[tmp-1].pop()
    par[tmp].append(i+2)
    par[tmp].append(i+2)
  print(*ANS)

for _ in range(int(input())):
  solve()