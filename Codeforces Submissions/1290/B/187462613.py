s=input()
n=len(s)
d={}
for i in range(26):
  d[chr(ord("a")+i)]=0
arr=[0 for i in range(n)]
c=0
i,j=0,0
while(j<n):
  d[s[j]]+=1
  if d[s[j]]==1:c+=1
  while(c==3):
    arr[i]=j
    d[s[i]]-=1
    if d[s[i]]==0:c-=1
    i+=1
  j+=1
for k in range(i,n):
  arr[k]=n
# print(arr)
for _ in range(int(input())):
  [i,j]=list(map(int,input().split(" ")))
  i-=1
  j-=1
  if i==j:
    print("yes")
  elif s[i]!=s[j]:
    print("yes")
  elif arr[i]<=j:
    print("yes")
  else:
    print("no")