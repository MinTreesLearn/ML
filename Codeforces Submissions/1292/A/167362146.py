import sys
input = lambda: sys.stdin.readline().rstrip()

n, q = map(int, input().split())

cur = [[0] * n for _ in range(2)]
blocked_c = 0
for _ in range(q):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    
    nx = x ^ 1
    if cur[x][y] == 0:
        delta = 1
    else:
        delta = -1
    cur[x][y] ^= 1
    
    for ny in range(y - 1, y + 2):
        if 0 <= ny < n:
            if cur[nx][ny] == 1:
                blocked_c += delta
                
    if blocked_c:
        print('No')
    else:
        print('Yes')