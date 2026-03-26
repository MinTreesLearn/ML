def d(a, b):
    return 1000000 * ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) + (abs(a[0] - b[0]) + abs(a[1] - b[1]))
n = int(input())
a = []
b = []
for i in range(n):
    b.append([int(x) for x in input().split()])
for i in range(n - 1):
    a.append(d(b[i], b[i + 1]))
a.append(d(b[0], b[-1]))
if n % 2:
    print('NO')
    quit()
for i in range(n // 2):
    if a[i] != a[i + n // 2]:
        print('NO')
        quit()
print('YES')

