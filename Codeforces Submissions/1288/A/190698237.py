import math
t = int(input())

while t:
  n, d = map(int, input().split())
  if (n + 1) ** 2 >= 4 * d:
    print("YES")
  else:
    print("NO")

  t -= 1