def func(arr, length, source):
    count = 0
    for temp_i in range(length):
        if source[temp_i] == 1:
            count += 1
        else:
            arr.append(count)
            count = 0
    else:
        arr.append(count)


n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
height = []
weight = []
rem = []
result = 0
func(height, n, a)
func(weight, m, b)
for i in range(1, int(k**0.5) + 1):
    if k % i == 0:
        rem.append((i, k // i))
        if i != k//i:
            rem.append((k // i, i))
for i in range(len(rem)):
    l_h = 0
    l_w = 0
    for j in range(len(height)):
        if height[j] >= rem[i][0]:
            l_h += height[j] - rem[i][0] + 1

    for g in range(len(weight)):
        if weight[g] >= rem[i][1]:
            l_w += weight[g] - rem[i][1] + 1
    result += l_h * l_w
print(result)