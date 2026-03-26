import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    visit = [0] * (2 * n + 1)
    for i in b:
        visit[i] = 1
    a = []
    for i in range(n):
        u = b[i]
        ok = 0
        for v in range(u + 1, 2 * n + 1):
            if not visit[v]:
                ok = 1
                a.append(u)
                a.append(v)
                visit[v] = 1
                break
        if not ok:
            a = [-1]
            break
    ans.append(" ".join(map(str, a)))
sys.stdout.write("\n".join(ans))