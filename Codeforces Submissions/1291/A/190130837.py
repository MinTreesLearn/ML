for _ in range(int(input())):
    x = int(input())
    y = list(input())
    z = []
    for i in y:
      if int(i) % 2 != 0:
        z.append(i)
      if len(z) == 2:
        break
    if len(z) == 2:
        print("".join(z))
    else:
        print(-1)