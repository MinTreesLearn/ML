[n,x]=list(map(int,input().split(" ")))
arr=[0 for i in range(x)]
# mex=0
index=0
ans=[]
if 0:
  none=0
else:
  for i in range(n):
    k=int(input())
    arr[k%x]+=1 
    while(arr[index%x]!=0):
      arr[index%x]-=1
      index+=1
    ans.append(index)
  for i in ans:
    print(i)