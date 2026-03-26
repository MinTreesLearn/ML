n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
win = [0, 0] #1 / 2
for i in range(n):
    if (a[i] == 1) and (b[i] == 0):
        win[0] += 1
    elif (a[i] == 0) and (b[i] == 1):
        win[1] += 1
if win[0] == 0:
    print(-1)
elif win[0] > win[1]:
    print(1)
else:
    print((win[1] + win[0]) // win[0])
