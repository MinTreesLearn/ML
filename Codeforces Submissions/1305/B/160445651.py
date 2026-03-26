import sys
input = sys.stdin.readline

s = input()[:-1]
i, j = 0, len(s)-1
c = 0
a = [-1]
b = [-1]
while i < j:
    if s[i] == '(':
        if i+1 != a[-1]:
            c += 1
            a.append(i+1)
    if s[j] == ')':
        if j+1 != b[-1]:
            c -= 1
            b.append(j+1)
    if c < 0:
        i += 1
    else:
        j -= 1

c = min(len(a), len(b))
x = 2*c-2
if x == 0:
    print(0)
else:
    print(1)
    print(x)
    print(*a[1:c], *sorted(b[1:c]))