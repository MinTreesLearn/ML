import bisect
for _ in range(int(input())):
  n,m=map(int,input().split())
  a=[int(i) for i in input().split()]
  p=[int(i)for i in input().split()]
  res="Yes"
  for i in range(n):
    a[i]=(a[i],i+1)
  a=sorted(a);p=sorted(p)
  for i in range(n):
    x=min(a[i][1],i+1);y=max(a[i][1],i+1)
    if x==y:continue
    pos=bisect.bisect(p,x)
    if  pos==0   :res=    "No"       ;break
    pos+=y-x-1
    if pos>=m +1    :res =   "No"       ;break
    if p[pos-1] != y-1:res =   "No"       ;break
  print(res)
