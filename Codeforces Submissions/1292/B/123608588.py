x0, y0, ax, ay, bx, by = [int(x) for x in input().strip().split()]
xs, ys, t = [int(x) for x in input().strip().split()]

lis = [(x0, y0)]

def getdis(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def getdisp(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)

for i in range(1, 100):
    xx, yy = lis[i - 1]
    lis.append((ax * xx + bx, ay * yy + by))

ans = 0
sp = (xs, ys)
for i in range(100):
    if getdisp(sp, lis[i]) > t:
        continue

    tt = t - getdisp(sp, lis[i])
    res = 1

    res_b = 0
    tmp = tt
    for j in range(i - 1, -1, -1):
        if getdisp(lis[j], lis[j + 1]) > tmp:
            break
        tmp -= getdisp(lis[j], lis[j + 1])
        res_b += 1
    
    res_f = 0
    tmp = tt
    for j in range(i + 1, 100):
        if getdisp(lis[j], lis[j - 1]) > tmp:
            break
        tmp -= getdisp(lis[j], lis[j - 1])
        res_f += 1
    
    ans = max(ans, res + max(res_b, res_f))

print(ans)
