from math import lcm, ceil
 
min = n = int(input())
sq = ceil(n ** 0.5) + 1

x = 1
while x < sq:
  if n % x == 0:
    y = n // x
    if lcm(x, y) != n:
      x += 1
      continue
    mx = max(x, y)
    if mx < min:
      min = mx
  x += 1

print(n // mx, mx)
