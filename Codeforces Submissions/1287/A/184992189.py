t = int(input())
while t > 0:
  t -= 1
  
  n = int(input())
  l = list(str(input()))
  
  ans = 0
  brk = False
  
  while brk != True:
    brk = False
    dx = 1
    act = False
    for i in l[:len(l)-1]:
      if i == 'A' and l[dx] == 'P':
        l[dx] = 'A'
        act = True
      dx += 1
    if act == False:
      brk = True
    else:
      ans += 1
  
  print(ans)