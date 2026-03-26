from collections import deque

def f():
  global a, n
  l = [0 for i in range(n)]
  q = deque()
  for i in range(n):
    while(len(q) and a[q[-1]] >= a[i]):
      q.pop()
    
    if(not len(q)):
      l[i] = (i+1)*a[i]
    else:
      l[i] = (i-q[-1])*a[i] + l[q[-1]]
    q.append(i)
  return l

n = int(input())
a = list(map(int,input().split()))

l = f()

a.reverse()

r = f()

a.reverse()
r.reverse()

mx = max([_ for _ in range(0,n)], key=lambda i: l[i]+r[i]-a[i])
for i in range(mx-1,-1,-1):
  a[i] = min(a[i],a[i+1])
for i in range(mx+1,n,1):
  a[i] = min(a[i],a[i-1])
print(*a)