q = int(input())
for i in range(q):
  w, e, r, t = map(int, input().split())
  y = max(w, e, r)
  u = min(w, e, r)
  o = w + e + r - y - u
  p = (y - u) + (y - o)
  if p <= t:
    if (t - p) % 3 == 0:
      print("YES")
    else:
      print("NO")
  else:
    print("NO")