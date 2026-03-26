from sys import stdin
input=lambda :stdin.readline()[:-1]

m=10**5
div=[[] for i in range(m)]
for i in range(1,m):
  for j in range(i,m,i):
    div[j].append(i)

def solve():
  a,b,c=map(int,input().split())
  ans=10**9
  for i in range(10**4):
    C=c+i
    for B in div[C]:
      for A in div[B]:
        res=i+abs(A-a)+abs(B-b)
        if res<ans:
          ans=res
          ANS=(A,B,C)
    
    C=c-i
    if C<1:
      continue
    for B in div[C]:
      for A in div[B]:
        res=i+abs(A-a)+abs(B-b)
        if res<ans:
          ans=res
          ANS=(A,B,C)
  
  print(ans)
  print(*ANS)
  

for _ in range(int(input())):
  solve()