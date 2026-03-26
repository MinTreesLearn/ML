import math


t = int(input())
result = []

for i in range(t):
    nd = list(map(int, input().split()))
    n = nd[0]
    d = nd[-1]

    flag = 0
    if (d <= n):
        result.append("YES")
        continue

    for i in range(n):
        if (math.ceil(i + (d/(i+1))) <= n):
            flag = 1
            break

    if (flag == 1):
        result.append("YES")
    else:
        result.append("NO")


for i in result:
    print(i)
