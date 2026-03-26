for _ in range(int(input())):
  a,b=map(int,input().split())
  if a==b:
    print(0)
  elif ((b-a)%2==1 and a<b) or ((b-a)%2==0 and a>b):
    print(1)
  else:
    print(2)
