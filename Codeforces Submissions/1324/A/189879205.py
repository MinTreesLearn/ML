for _ in range(int(input())):
  n=int(input())
  a=list(map(int,input().split()))
  flag=False
  for i in range(n):
    for j in range(n):
      if abs(a[i]-a[j])%2!=0:print("NO");flag=True;break;
    if flag:break
  if not flag: print("YES")