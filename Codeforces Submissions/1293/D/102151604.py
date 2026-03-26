from math import *
 
x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
 
INF = int(1e16 + 233)
x = [x0]
y = [y0]
while x[-1] < INF and y[-1] < INF:
    x.append(ax*x[-1]+bx)
    y.append(ay*y[-1]+by)
 
n = len(x)
ans = 0
for i in range(n):
    for j in range(i, n):
        dist = abs(x[i]-x[j]) + abs(y[i]-y[j])
        fix1 = abs(x[i]-xs) + abs(y[i]-ys)
        fix2 = abs(x[j]-xs) + abs(y[j]-ys)
        if dist + fix1 <= t or dist + fix2 <= t:
            ans = max(ans, j-i+1)
print(ans)