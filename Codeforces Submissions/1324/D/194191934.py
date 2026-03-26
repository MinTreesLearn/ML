n = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))
D = [0] * n

for i in range(n):
    D[i] = A[i] - B[i]

D.sort()

# find pairs which gives Di + Dj > 0

total = 0
beg = 0
end = n - 1

while (end >= beg):
    while (beg < end and D[beg] + D[end] <= 0):
        beg += 1
    total += max(end - beg, 0)
    end -= 1

print(total)
