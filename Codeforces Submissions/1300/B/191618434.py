t = int(input())
for i in range(t):
    n = int(input())
    m = 2 * n
    arr = list(map(int, input().split()))[:m]
    arr.sort()
    print(abs(arr[n-1] - arr[n]))