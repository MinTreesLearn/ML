import sys
input = sys.stdin.readline
from bisect import bisect_left

n = int(input())
print('?', 1, n)
sys.stdout.flush()
m = (n + 1) // 2
l1 = [[0] * 26 for _ in range(m + 1)]
for i in range(n * (n + 1) // 2):
    s = input()[:-1]
    if len(s) <= m:
        for j in range(len(s)):
            l1[len(s)][ord(s[j]) - 97] += 1
for i in range(m, 0, -1):
    for j in range(26):
        l1[i][j] -= l1[i - 1][j]
for i in range(m):
    for j in range(26):
        l1[i][j] -= l1[i + 1][j]
if n > 1:
    n = n - 1
    print('?', 1, n)
    sys.stdout.flush()
    m = (n + 1) // 2
    l2 = [[0] * 26 for _ in range(m + 1)]
    for i in range(n * (n + 1) // 2):
        s = input()[:-1]
        if len(s) <= m:
            for j in range(len(s)):
                l2[len(s)][ord(s[j]) - 97] += 1
    for i in range(m, 0, -1):
        for j in range(26):
            l2[i][j] -= l2[i - 1][j]
    for i in range(m):
        for j in range(26):
            l2[i][j] -= l2[i + 1][j]
    n += 1
x = [-1] * n
y = [-1] * n
for i in range(n):
    if i % 2 == 0:
        for j in range(26):
            if l1[i//2+1][j] >= 1:
                l1[i//2+1][j] -= 1
                x[i] = j
                break
        for j in range(26):
            if l1[i//2+1][j] >= 1:
                l1[i//2+1][j] -= 1
                y[i] = j
                break
    else:
        for j in range(26):
            if l2[i//2+1][j] >= 1:
                l2[i//2+1][j] -= 1
                x[i] = j
                break
        for j in range(26):
            if l2[i//2+1][j] >= 1:
                l2[i//2+1][j] -= 1
                y[i] = j
                break
ans = [0] * n
m = (n + 1) // 2
ll = []
if n % 2 == 1:
    ll.append(n // 2)
    for i in range(n // 2):
        ll.append(n // 2 - i - 1)
        ll.append(n // 2 + i + 1)
else:
    for i in range(n // 2):
        ll.append(n // 2 - i - 1)
        ll.append(n // 2 + i)
ans[ll[0]] = x[-1]
t = 0
for i in range(n - 1):
    if t == 0:
        if x[n - i - 2] == x[n - i - 1]:
            ans[ll[i + 1]] = y[n - i - 2]
            t = 1
        else:
            ans[ll[i + 1]] = x[n - i - 2]
    else:
        if x[n - i - 2] == y[n - i - 1]:
            ans[ll[i + 1]] = y[n - i - 2]
        else:
            ans[ll[i + 1]] = x[n - i - 2]
            t = 0
print('! ', *map(lambda x:chr(x+97), ans), sep='')