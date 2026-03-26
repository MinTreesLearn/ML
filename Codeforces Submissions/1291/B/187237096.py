for _ in range(int(input())):
  n=int(input())
  arr=list(map(int,input().split(" ")))
  if n%2:
    yes=1
    for i in range(n):
      if arr[i]<min(i,n-1-i):
        yes=0
        break
    print("yes" if yes else "no")
  else:
    yes=1
    for i in range(n):
      if arr[i]<min(i,n-1-i):
        yes=0
        break
    if arr[n//2]==n//2-1 and arr[n//2-1]==n//2-1:
      yes=0
    print("yes" if yes else "no")