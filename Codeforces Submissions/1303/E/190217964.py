from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  s=input()
  t=input()
  ns=len(s)
  nt=len(t)
  inf=10**9
  for i in range(nt):
    t1=t[:i]
    t2=t[i:]
    n1=len(t1)
    n2=len(t2)
    dp=[-1]*(n1+1)
    dp[0]=0
    for j in range(ns):
      ndp=[-1]*(n1+1)
      for k in range(n1+1):
        if dp[k]==-1:
          continue
        ndp[k]=max(ndp[k],dp[k])
        if k!=n1 and s[j]==t1[k]:
          ndp[k+1]=max(ndp[k+1],dp[k])
        if dp[k]!=n2 and s[j]==t2[dp[k]]:
          ndp[k]=max(ndp[k],dp[k]+1)
      dp=ndp
    if dp[n1]==n2:
      print('YES')
      return
  print('NO')

for _ in range(int(input())):
  solve()