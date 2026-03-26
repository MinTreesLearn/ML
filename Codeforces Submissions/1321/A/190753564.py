n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

total1 = sum(arr1)
total2 = sum(arr2)
count = 0
ones = 0

for i in range(len(arr1)):
    if arr1[i] == 1 and arr2[i] == 0:
        count += 1
    elif arr1[i] == 1 and arr2[i] == 1:
        ones += 1

needed = -1

if total1 > total2:
    print(1)
    exit()

if count >= 1 and total1 <= total2:
    total2 = total2 - ones
    needed = total2//count + 1


print(needed)