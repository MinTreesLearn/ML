for _ in[0]*int(input()):
  n=input()
  a=[*map(int,input().split())]
  if a[0]%2==0: print('1\n1')
  elif n=='1': print(-1)
  elif a[1]%2==0: print('1\n2')
  else: print('2\n1 2')