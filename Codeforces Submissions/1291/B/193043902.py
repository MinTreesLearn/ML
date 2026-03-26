# LUOGU_RID: 101844865
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    l = 0
    while l < n and a[l] >= l:
        l += 1
    r = n
    while r > 0 and a[r - 1] >= n - r:
        r -= 1
    print(l > r and 'Yes' or 'No')