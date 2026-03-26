from math import lcm, ceil
 
# primes = []
 
# def seive(lim):
#   lim = ceil(lim ** 0.5) + 10
#   p = [True] * lim
#   p[0] = p[1] = False
#   i = 2
#   while i < lim:
#     if p[i]:
#       primes.append(i)
#       j = i*i
#       while j < lim:
#         p[j] = False
#         j += i
#     i += 1
 
min = n = int(input())
sq = ceil(n ** 0.5) + 100
# seive(n)
x = 1
while x <= sq:
  if n % x == 0:
    y = n // x
    if lcm(x, y) != n:
      x += 1
      continue
    m = max(x, y)
    if m < min:
      min = m
  x += 1
 
a, b = sorted([min, n // min])
print(a, b)