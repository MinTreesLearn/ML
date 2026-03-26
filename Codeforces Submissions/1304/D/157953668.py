import sys
input = sys.stdin.readline

t = int(input())
ans = []
for _ in range(t):
    n, s = input().rstrip().split()
    n = int(n)
    s = list(s)
    x = [0]
    for i in range(n - 1):
        if s[i] == ">":
            x.append(i + 1)
    x.append(n)
    p = [0] * n
    u = 1
    for i in range(len(x) - 2, -1, -1):
        for j in range(x[i], x[i + 1]):
            p[j] = u
            u += 1
    ans.append(" ".join(map(str, p)))
    p = []
    u, v = n - len(x) + 2, n - len(x) + 3
    p.append(u)
    u -= 1
    for i in reversed(s):
        if i == "<":
            p.append(u)
            u -= 1
        else:
            p.append(v)
            v += 1
    p.reverse()
    ans.append(" ".join(map(str, p)))
sys.stdout.write("\n".join(ans))