n=int(input())
s=input()
c=0
for i in s:
  c+=1 if i=="(" else 0
if c!=n/2:
  print(-1)
  exit()
ans=0
dir=0
c=0
l=0
for i in s:
  if c==0:
    if dir==-1:
      ans+=l
    l=0
    dir =1 if i=="(" else -1
  if i=="(":
    c+=1
    l+=1
  else:
    c-=1
    l+=1
if c==0:
    if dir==-1:
      ans+=l
print(ans)
  