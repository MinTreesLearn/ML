x0, y0, ax, ay, bx, by = map(int, input().split())
x, y, t = map(int, input().split())
xaxis = [];yaxis = [];dis = 3*(10 ** 16);
xaxis.append(x0)
yaxis.append(y0)
lim=120;ans=0
for i in range(0, lim):
    xaxis.append(xaxis[i] * ax + bx)
    yaxis.append(yaxis[i] * ay + by)
for j in range(0,lim):
    inx=j
    tim = 0
    cnt = 0
    x1=x
    y1=y
    for i in range(inx, -1, -1):
        tmp = abs(xaxis[i] - x) + abs(yaxis[i] - y)
        if tim + tmp > t:
            break
        x = xaxis[i]
        y = yaxis[i]
        tim += tmp
        cnt += 1

    for i in range(inx + 1, lim):
        tmp = abs(xaxis[i] - x) + abs(yaxis[i] - y)
        if tim + tmp > t:
            break
        x = xaxis[i]
        y = yaxis[i]
        tim += tmp
        cnt += 1
    x=x1
    y=y1
    ans=max(ans,cnt)

print(ans)

