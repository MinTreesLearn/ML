i=input
for _ in[0]*int(i()):
  a,b,c=sorted(map(int,i().split()))
  r=(a>0)+(b>0)+(c>0)+(min(a,b,c)>3)
  if (c>1 and b>1):r+=1;c-=1;b-=1
  if (c>1 and a>1):r+=1;a-=1
  if (b>1 and a>1):r+=1
  print(r)