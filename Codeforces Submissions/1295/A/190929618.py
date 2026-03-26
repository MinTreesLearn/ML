t=int(input())
for num in range(0,t):
  i=int(input())
  o=i//2
  p=i%2
  if p==0:
    print(o*'1')
  else:
    o=o-1
    print('7'+o*'1')
  