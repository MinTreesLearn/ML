maxn = 10**4
for _ in range(int(input())):
    a = list(map(int, input().split()))
    curr = [10**5] * (2 * maxn + 10)
    pair = [0] * (2 * maxn + 10)
    for i in range(1, 2 * maxn + 1):
        for j in range(i, 2 * maxn + 1, i):
            if abs(j - a[-1]) < curr[i]:
                curr[i] = abs(j - a[-1])
                pair[i] = (i, j)
        curr[i] += abs(i - a[1])
    ans, x, y, z = 10**5, -1, -1, -1
    for i in range(1, 2 * maxn + 1):
        for j in range(i, 2 * maxn + 1, i):
            if abs(i - a[0]) + curr[j] < ans:
                ans = abs(i - a[0]) + curr[j]
                x = i
                y = j
                z = pair[y][1]
    print(ans)
    print(x, y, z)
