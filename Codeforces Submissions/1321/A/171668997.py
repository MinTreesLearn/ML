import sys

input = sys.stdin.readline

n = int(input())
r = list(map(int, input().split()))
b = list(map(int, input().split()))

f = 0
s = 0
for i in range(n):
    if r[i] == 1 and b[i] == 1:
        pass
    else:
        if r[i] == 1:
            f += 1
        if b[i] == 1:
            s += 1

if f == 0:
    print(-1)
else:
    if f > s:
        print(1)
    elif f == s:
        print(2)
    else:
        print(s // f + 1)