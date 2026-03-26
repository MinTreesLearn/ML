import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))

max_r = -1
max_r_mid = -1
for mid in range(n):
    temp_r = 0
    temp_r += li[mid]

    max_pv = li[mid]
    cur_i = mid
    while True:
        cur_i -= 1
        if cur_i < 0:
            break
        max_pv = min(li[cur_i], max_pv)
        temp_r += max_pv

    max_pv = li[mid]
    cur_i = mid
    while True:
        cur_i += 1
        if cur_i >= n:
            break
        max_pv = min(li[cur_i], max_pv)
        temp_r += max_pv

    if temp_r > max_r:
        max_r = temp_r
        max_r_mid = mid

result = [0] * n
result[max_r_mid] = li[max_r_mid]
for i in range(max_r_mid - 1, -1, -1):
    result[i] = min(result[i + 1], li[i])

for i in range(max_r_mid + 1, n):
    result[i] = min(result[i - 1], li[i])

print(*result)