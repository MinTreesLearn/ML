[h,n]=list(map(int,input().split()))
arr=list(map(int,input().split()))
summ=[arr[0]]
for i in arr[1:]:
  summ.append(i+summ[-1])
mini=min(summ)
k=sum(arr)
if mini+h>0 and k>=0:
  print(-1)
elif mini+h<=0:
  ans=0
  i=0
  while(h>0):
    h+=arr[i%n]
    i+=1
    ans+=1
  print(ans)
else:
  k=-1*k
  # print(mini,k)
  ans=((h+mini+k-1)//k)*n
  h-=((ans)//n)*k
  i=0
  # print(ans,h)
  while(h>0):
    h+=arr[i%n]
    i+=1
    ans+=1
  print(ans)