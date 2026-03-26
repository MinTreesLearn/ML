import sys
input = sys.stdin.readline

n, m = map(int, input().split())
g = [input()[:-1] for _ in range(n)]

d = set(g)
c = 0
q = {'ES':'T', 'SE':'T', 'ET':'S', 'TE':'S', 'TS':'E', 'ST':'E'}
for i in range(n-1):
    for j in range(i+1, n):
        x = ''
        for k in range(m):
            if g[i][k] == g[j][k]:
                x += g[i][k]
            else:
                x += q[g[i][k] + g[j][k]]
        if x in d:
            c += 1

print(c//3)
