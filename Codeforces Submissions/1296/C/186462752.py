for _ in range(int(input())):
    n = int((input()))
    s = input()
    cur = (0, 0) 
    dic = {(0, 0): 0}
    l, r = -1, n
    for i, a in enumerate(s):      
      f, s = cur
      if a == 'L':        
        cur = (f - 1, s)
      if a == 'R':
        cur = (f + 1, s)
      if a == 'U':
        cur = (f, s + 1)
      if a == 'D':
        cur = (f, s - 1)      
      if cur in dic:        
        if i - dic[cur] + 1 < r - l + 1:          
          l, r = dic[cur], i          
      dic[cur] = i + 1    
    if l == -1:
      print(-1)
    else:
      print(l + 1, r + 1)
              