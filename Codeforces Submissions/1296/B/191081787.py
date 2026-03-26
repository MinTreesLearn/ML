from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n=int(input())
  ans=n
  while n>=10:
    x=n//10
    ans+=x
    n-=9*x
  print(ans)


for _ in range(int(input())):
  solve()