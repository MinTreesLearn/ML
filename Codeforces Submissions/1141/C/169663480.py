import sys
input = sys.stdin.readline


n = int(input())
w = list(map(int, input().split()))
x = n-1

l, r, d = 0, 0, 0
c = 0
q = [0]*n
for i, j in enumerate(w):
    if c <= 0:
        l1 = i
        c = j
    else:
        c += j

    if c > d:
        d = c
        l = l1
        r = i + 1

if d == x:
    q[l] = 1
    for i in range(l+1, n):
        q[i] = q[i-1] + w[i-1]
    for i in range(l-1, -1, -1):
        q[i] = q[i+1] - w[i]

    if sorted(q) == list(range(1, n+1)):
        print(' '.join(map(str, q)))
        exit(0)

l0, r0, d0 = 0, 0, 0
c = 0
for i, j in enumerate(w):
    if c >= 0:
        l1 = i
        c = j
    else:
        c += j

    if c < d0:
        d0 = c
        l0 = l1
        r0 = i + 1


if d0 == -x:
    q[r0] = 1
    for i in range(r0+1, n):
        q[i] = q[i-1] + w[i-1]
    for i in range(r0-1, -1, -1):
        q[i] = q[i+1] - w[i]

    if sorted(q) == list(range(1, n+1)):
        print(' '.join(map(str, q)))
        exit(0)

print(-1)
