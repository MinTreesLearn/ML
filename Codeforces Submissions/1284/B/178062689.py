import sys
n = int(input())
m = 1<<20
zc = 0
fc = [0] * m
lc = [0] * m
for inp in sys.stdin:
  a = [*map(int,inp.split()[1:])]
  z = all(a[i] >= a[i+1] for i in range(len(a)-1))
  zc += z
  if z:
    fc[a[0]] += 1
    lc[a[-1]] += 1
ans = n*n - zc*zc
less = 0
for i in range(m):
  ans += fc[i] * less
  less += lc[i]
print(ans)
