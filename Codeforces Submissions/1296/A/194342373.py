t=int(input())
for i in range(t):
  
  n=int(input())
  m=input().split()
  a=[int(i) for i in m]
  odd=0
  even=0
  for j in a:
    if j%2==0:
      even+=j
    else:
      odd+=j
  if sum(a)%2==1:
    print("YES")
  else:
    if odd>1 and even>1:
      print("YES")
    else:
      print("NO")