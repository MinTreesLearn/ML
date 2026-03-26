n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
lsch, wsch = 0, 0
for i in range(n):
    if a[i] == 1 and b[i] == 0:
        wsch += 1
    elif a[i] == 0 and b[i] == 1:
        lsch += 1
if wsch == 0:
    print(-1)
else:
    print((lsch + wsch) // wsch)