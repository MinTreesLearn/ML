for t in range(int(input())):
  n=int(input())
  num=list(map(int,input().split()))
  e=0
  for i in num:
    if i%2==0:
      e+=1
  o=n-e
  if e==n or (e==0 and o%2==0):
    print("NO")
  else:
    print("YES")