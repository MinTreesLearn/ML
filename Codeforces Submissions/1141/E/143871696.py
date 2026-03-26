k, n = map(int, input().split())
arr = [int(x) for x in input().split()]

sum = 0
for i in range(0, n):
    sum = sum + arr[i]
    if sum + k <= 0:
        print(i + 1)
        exit()

if sum >= 0 : 
    print(-1)
    exit()

l = 1
h = 10000000000000
ans = 1000000000000000000
    
while l <= h :
    mid = (l + h) >> 1
    f = 0
    pre = 0
    
    for i in range(0, n):
        if sum * (mid - 1) + arr[i] + k + pre <= 0:
            f = 1
            ans = min(ans, (mid - 1) * n + (i + 1))
            break   
        pre = pre + arr[i] 

    if f == 1:
        h = mid - 1
    else:
        l = mid + 1

print(ans)