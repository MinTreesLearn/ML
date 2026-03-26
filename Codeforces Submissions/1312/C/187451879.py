for _ in range(int(input())):
  [n,k]=list(map(int,input().split(" ")))
  arr=list(map(int,input().split(" ")))
  arr.sort(reverse=True)
  if arr[0]==0:
    print("yes")
    continue
  if k==0:
    print("no")
    continue
  if k==1:
    print("yes")
    continue
  pow=0
  while(k**pow<arr[0]):
    pow+=1
  c=[0 for i in range(pow+2)]
  for i in arr:
    ind=0
    while(i):
      c[ind]+=i%k
      i=i//k
      ind+=1
  t=1
  for i in c:
    if i>=2:
      t=0
  print("yes" if t else "no")