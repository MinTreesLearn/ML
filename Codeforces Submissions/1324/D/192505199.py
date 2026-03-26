n = int(input())

array1 = list(map(int, input().split()))
array2 = list(map(int, input().split()))

array = []
for i in range(n):
    array.append(array1[i] - array2[i])

array.sort()

cnt = 0
for i in range(n - 1):
    l, r = i, n - 1
    while r - l > 1:
        m = (l + r) // 2

        if array[i] + array[m] <= 0:
            l = m
        else:
            r = m

    if array[i] + array[r] > 0:
        cnt += n - r

print(cnt)