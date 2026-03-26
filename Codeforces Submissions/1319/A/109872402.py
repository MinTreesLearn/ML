from math import ceil
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x = 0
y = 0
for i in range(n):
    if a[i] == 1 and b[i] == 0:
        x += 1
    elif a[i] == 0 and b[i] == 1:
        y += 1
if x == 0:
    print(-1)
else:
    print(ceil((y+1)/x))