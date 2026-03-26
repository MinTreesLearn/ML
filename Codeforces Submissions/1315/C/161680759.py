#import io, os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t=int(input())
for _ in range(t):
  n=int(input())
  b=list(map(int,input().split()))
  a=[]
  for i in range(1,2*n+1):
    a.append(i)
  perm=[]
  visited={}
  for i in b:
    visited.update({i:1})
  flag=False
  for i in b:
    perm.append(i)
    for j in a:
      if not j in visited:
        if j>i:
          perm.append(j)
          visited.update({j:1})
          break
        
    else:
      flag=True
  if flag:print(-1)
  else:print(*perm)