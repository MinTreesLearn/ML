from cmath import inf
from sys import stdin, stdout

n = int(stdin.readline().strip())
arr = list(map(int, stdin.readline().split()))


mono_stack = []
non_dec_sum = [0] * n
prefix_sum = 0

for i, num in enumerate(reversed(arr)):
    count = 1

    while mono_stack and num <= mono_stack[-1][0]:
        val, cc = mono_stack.pop()
        prefix_sum -= val * cc
        count += cc
    prefix_sum += (num * count)
    mono_stack.append((num, count))
    non_dec_sum[~i] = prefix_sum


mono_stack.clear()
prefix_sum = 0

best_peak = -1
best_sum = -inf

for i, num in enumerate(arr):
    count = 1

    while mono_stack and num <= mono_stack[-1][0]:
        val, cc = mono_stack.pop()
        prefix_sum -= val * cc
        count += cc
    prefix_sum += (num * count)
    mono_stack.append((num, count))
    if prefix_sum + non_dec_sum[i] - num > best_sum:
        best_peak = i
        best_sum = prefix_sum + non_dec_sum[i] - num

# print(best_peak)

ans = [0] * n

ans[best_peak] = arr[best_peak]
prev = arr[best_peak]
for i in range(best_peak + 1, n):
    ans[i] = min(arr[i], prev)
    prev = ans[i]

prev = arr[best_peak]
for i in range(best_peak - 1, -1, -1):
    ans[i] = min(arr[i], prev)
    prev = ans[i]

print(*ans)