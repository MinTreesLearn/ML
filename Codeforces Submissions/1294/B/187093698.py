for _ in range(int(input())):
    n = int(input())
    cords = []
    for i in range(n):
      a, b = map(int, input().split())
      cords.append([a, b])
    cords = sorted(cords, key = lambda t: t[0]) 
    cords = sorted(cords, key = lambda t: t[1])    
    prevx = 0
    prevy = 0
    ans = ''
    flag = False
    for a, b in cords:
      if a < prevx:           
        flag = True
        break      
      xcord = a - prevx
      ycord = b - prevy
      ans += xcord*"R" + ycord*"U"
      prevx = a
      prevy = b
    if flag:
      print('NO')
    else:
      print('YES')
      print(ans)