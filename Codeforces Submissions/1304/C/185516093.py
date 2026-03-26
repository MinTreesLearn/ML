#import sys
#input = sys.stdin.readline

q = int(input())
for _ in range(q):
  ans = "YES"
  n,m = map(int,input().split())
  mh = ml = m
  tx = 0
  for _ in range(n):
    t,l,h = map(int, input().split())
    if tx < t:
      mh += t - tx
      ml -= t - tx
      tx = t
    mh = min(mh, h)
    ml = max(ml, l)
    if mh < ml:
      ans = "NO"
  print(ans)
