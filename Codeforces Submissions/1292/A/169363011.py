from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

t = 1

for _ in range(t):

  n, q = map(int,input().split())

  hashm = {}

  counter = 0
  
  for i in range(q):

    r, c = map(int,input().split())

    if (r,c) in hashm:

      if (2 - ((r+1)%2), c-1) in hashm:
        counter -= 1
      if (2 - ((r+1)%2), c) in hashm:
        counter -= 1
      if (2 - ((r+1)%2), c+1) in hashm:
        counter -= 1
      hashm.pop((r,c))


    else:


      if (2 - ((r+1)%2), c-1) in hashm:
        counter += 1
      if (2 - ((r+1)%2), c) in hashm:
        counter += 1
      if (2 - ((r+1)%2), c+1) in hashm:
        counter += 1
      hashm[(r,c)] = None

    if counter == 0:
      print("YES")
    else:
      print("NO")