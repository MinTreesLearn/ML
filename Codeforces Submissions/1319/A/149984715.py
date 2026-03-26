n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
up = 0
down = 0
for i in range(n):
    if a[i] == 1 and b[i] == 0:
        up += 1
    elif a[i] == 0 and b[i] == 1:
        down += 1
if up == 0:
    print(-1)
else:
    down += 1
    print((down + up - 1) // up)