q = int(input())
for i in range(q):
  w = input()
  a = [i for i in w]
  e = 0
  r = 0
  t = 0
  for i in range(len(w)):
    if w[i] == "1":
      r += e
      t = 1
      e = 0
    else:
      if t > 0:
        e += 1
  print(r)