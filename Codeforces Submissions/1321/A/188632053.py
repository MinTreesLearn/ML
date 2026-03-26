import math

n = int(input())
arr = list(map(int, input().split()))
arr2 =list(map(int, input().split()))

total1 = 0
total2 = 0
arr_count = 0

total1 = sum(arr)
total2 = sum(arr2)

if total2 == len(arr2):
    print(-1)
    exit()

for i in range(len(arr)):
    if arr[i] == 1 and arr[i] == arr2[i]:
        arr_count += 1

if arr_count == total1:
    print(-1)
    exit()

total1 -= arr_count
total2 -= arr_count

val = math.ceil((total2+1) / (total1))

print(val)


