
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
g = [input()[:-1] for _ in range(n)]

d = set(g)
c = 0
q = ord('S') + ord('E') + ord('T')
for i in range(n-1):
    for j in range(i+1, n):
        x = []
        for k in range(m):
            if g[i][k] == g[j][k]:
                x.append(g[i][k])
            else:
                x.append(chr(q - ord(g[i][k]) - ord(g[j][k])))
        if ''.join(x) in d:
            c += 1

print(c//3)