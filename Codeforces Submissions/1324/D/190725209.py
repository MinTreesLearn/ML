n = int(input())
teacher = list(map(int, input().split()))
student = list(map(int, input().split()))
store = []

for i in range(n):
    store.append(teacher[i] - student[i])

store.sort()
l, r = 0, n - 1
res = 0

while l < r:
    cur = store[r] + store[l]
    if cur > 0:
        res += r - l
        r -= 1
    else:
        l += 1

print(res)
