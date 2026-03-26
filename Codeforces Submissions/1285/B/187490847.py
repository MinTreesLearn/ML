for _ in range(int(input())):
  n=int(input())
  arr=list(map(int,input().split(" ")))
  s=sum(arr)
  a=0
  mini=0
  new=[]
  ans=1
  for i in range(n):
    a+=arr[i]
    if a<=0:
      ans=0
      break
    mini=min(a,mini)
    new.append(mini)
  summ=0
  if ans==0:
    print("no")
    continue
  # print(new)
  for i in range(n-1,0,-1):
    summ+=arr[i]
    # print(summ)
    if summ+new[i-1]<=0:
      ans=0
      break
  print("yes" if ans else "no")