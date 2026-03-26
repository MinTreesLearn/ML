n = int(input())
a = list(map(int , input().split()))
b = list(map(int , input().split()))
k = 0
k1 = 0
for i in range(0 , len(a)):
    if a[i] > b[i]:
        k += 1
    if a[i] < b[i]:
        k1 += 1
if k == 0:
    print(-1)
    exit()
k1 = k1 // k + 1
print(k1)