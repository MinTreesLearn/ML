from collections import deque
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def f(i, j):
    return i * n + j

def bfs(sx, sy):
    q = deque()
    q.append((sx, sy))
    ans[sx][sy] = "X"
    z = f(sx, sy)
    while q:
        i, j = q.popleft()
        for di, dj, _ , d in v:
            ni, nj = i + di, j + dj
            if not 0 <= ni < n or not 0 <= nj < n:
                continue
            if not ans[ni][nj] == "?" or s[ni][nj] ^ z:
                continue
            ans[ni][nj] = chr(d)
            q.append((ni, nj))
    return

n = int(input())
s = []
for _ in range(n):
    xy = list(map(int, input().split()))
    s0 = []
    for i in range(n):
        if xy[2 * i] > 0:
            s0.append(f(xy[2 * i] - 1, xy[2 * i + 1] - 1))
        else:
            s0.append(-1)
    s.append(s0)
v = []
v.append((-1, 0, ord("U"), ord("D")))
v.append((1, 0, ord("D"), ord("U")))
v.append((0, -1, ord("L"), ord("R")))
v.append((0, 1, ord("R"), ord("L")))
ans = [["?"] * n for _ in range(n)]
for x in range(n):
    for y in range(n):
        if ans[x][y] == "?":
            if not s[x][y] ^ f(x, y):
                bfs(x, y)
            elif not s[x][y] ^ -1:
                ok = 0
                for dx, dy, d, _ in v:
                    nx, ny = x + dx, y + dy
                    if not 0 <= nx < n or not 0 <= ny < n:
                        continue
                    if not s[nx][ny] ^ -1:
                        ans[x][y] = chr(d)
                        ok = 1
                        break
                if not ok:
                    print("INVALID")
                    exit()
for i in range(n):
    if ans[i].count("?"):
        print("INVALID")
        exit()
    ans[i] = "".join(ans[i])
print("VALID")
sys.stdout.write("\n".join(ans))