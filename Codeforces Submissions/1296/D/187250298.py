import math
[n,a,b,k]=list(map(int,input().split(" ")))
new=list(map(int,input().split(" ")))
new=[(i-a)%(a+b) for i in new]
arr=[]
ans=0
for i in new:
  # print(i)
  if i>b:
    ans+=1
  else:
    arr.append(i)
arr.sort()
i=0
# print(arr)
while(i<len(arr) and k>0):
  k-=math.ceil(arr[i]/a)
  # print(k)
  if k>=0:
    ans+=1
    i+=1
    # print(ans)
print(ans)