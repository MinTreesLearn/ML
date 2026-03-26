n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
arr = [a[i] - b[i] for i in range(n)]
arr.sort(reverse=True)
r = n - 1
res = 0

for i in range(n):
  while r > i and arr[i] + arr[r] <= 0:
    r -= 1
  #print(f'i: {i}, r: {r}')
  if r - i > 0:
    res += r - i
print(res)