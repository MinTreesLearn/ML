import sys
input = sys.stdin.buffer.readline
N = int(input())
a = list(map(int, input().split()))

s = [(0, N)]
for x in a:
  c = 1
  while s[-1][0] * c >= x * s[-1][1]:
    y, d = s.pop()
    x += y
    c += d
  s.append((x, c))

s.reverse()
s.pop()
i = 0
while len(s):
  x, c = s.pop()
  for j in range(i, i + c): print(x / c)
  i += c