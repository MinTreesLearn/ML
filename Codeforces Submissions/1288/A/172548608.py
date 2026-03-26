t=int(input())
for e in range(t):
  n,d=list(map(int, input().split()))
  l=0
  r=n
  a=[]
  eps=1e-6
  while r-l>1:
    m1=int(l+(r-l)/3-0.000000001)
    m2=int(l+(r-l)/3*2-0.000000001)
    if m1+d/(m1+1)>m2+d/(m2+1):
      l=l+(r-l)/3
    elif m1+d/(m1+1)<m2+d/(m2+1):
      r=l+(r-l)/3*2
    else:
      if m1+d/(m1+1)<=min(n,d):
        a='YES'
        break
      else:
        l=l+(r-l)/3
        r=l+(r-l)/3*2
  if l!=0:
    q=int(l-0.000000001)+1
  else:
    q=0
  if a=='YES' or q+d/(q+1)<=min(n,d):
    print('YES')
  else:
    print('NO')