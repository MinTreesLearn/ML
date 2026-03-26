
def d(pa, pb):
    return abs(pa[0]-pb[0])+abs(pa[1]-pb[1])

put = input().split()
x0, y0, ax, ay, bx, by = int(put[0]), int(put[1]), int(put[2]), int(put[3]), int(put[4]), int(put[5])
put = input().split()
xs, ys, t = int(put[0]), int(put[1]), int(put[2])
p = list()
while x0 <= 10 ** 19 and y0 <= 10 ** 19:
    p.append([x0,y0])
    x0 = ax * x0 + bx
    y0 = ay * y0 + by
m = len(p)
bst = 0
sp = [xs, ys]
for i in range(m):
    for j in range(i, m):
        dsj = d(sp, p[j])
        for k in range(j, m):
            totd1 = dsj + d(p[i],p[j])+d(p[i],p[k])
            totd2 = dsj + d(p[j],p[k])+d(p[i],p[k])
            if totd1 <= t or totd2 <= t:
                if bst < (k - i + 1):
                    bst= k - i + 1
print(bst)