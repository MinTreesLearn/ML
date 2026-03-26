import bisect


length = int(input())
num1 = list(map(int, input().split()))
num2 = list(map(int, input().split()))

for i in range(length):
    num1[i] -= num2[i]

num1.sort()
count = 0

for i in range(length):
    if num1[i] <= 0:
        count += length - bisect.bisect(num1, abs(num1[i]))
    else:
        count += length - i-1
print(count)