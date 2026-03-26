import sys
input = sys.stdin.readline

n = int(input())
w = list(map(int, input().split()))
d = [-1]*35
for i in range(n):
    x = w[i]
    j = 0
    while x:
        if x % 2:
            if d[j] == -1:
                d[j] = i
            else:
                d[j] = -2
        x >>= 1
        j += 1
c = -1
for i in d:
    if i not in [-1, -2]:
        c = i
if c == -1:
    print(' '.join(map(str, w)))
else:
    print(w[c], ' '.join(map(str, w[:c])), ' '.join(map(str, w[c+1:])))