import sys
input = sys.stdin.readline

n = int(input())
s = input()[:-1]

c = 0
d, e = 0, -1
ans = 0
for i in range(n):
    if s[i] == '(':
        c += 1
    else:
        c -= 1
    if d == 0 and c < 0:
        d = 1
        e = i
    elif d == 1 and c >= 0:
        d = 0
        ans += i - e + 1
        e = -1
if e != -1:
    ans += n-e
if c == 0:
    print(ans)
else:
    print(-1)