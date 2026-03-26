n = int(input())
arr = list(map(int, input().split()))
temp = []
store = {}
res = 0

for i in range(n):
    group = i - arr[i]
    temp.append(group)
    if group not in store:
        store[group] = arr[i]
    else:
        store[group] += arr[i]

    res = max(res, store[group])

print(res)

