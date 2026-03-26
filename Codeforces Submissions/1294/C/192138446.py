from sys import stdin
input=lambda :stdin.readline()[:-1]

def solve():
  n=int(input())
  ans=[]
  now=n
  for i in range(2,int(n**0.5)+10):
    if now%i==0 and len(ans)<=1:
      ans.append(i)
      now//=i
  ans.append(now)
  if len(set(ans))==3 and min(ans)!=1:
    print('YES')
    print(*ans)
  else:
    print('NO')

for _ in range(int(input())):
  solve()