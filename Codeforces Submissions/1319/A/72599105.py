def ceil(a, b):
    return a // b + (a % b != 0)
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt1 = 0
cnt2 = 0
for i in range(n):
    cnt1 += (a[i] == 0 and b[i] == 1)
    cnt2 += (a[i] == 1 and b[i] == 0)
if cnt2 == 0:
    print(-1)
else:
    print(ceil(cnt1 + 1, cnt2))
