import sys
input = sys.stdin.readline

n, q = map(int, input().split())
w = [[0]*(n+2) for _ in range(2)]
c = 0
for _ in range(q):
    i, j = map(int, input().split())
    if w[i-1][j] == 0:
        w[i-1][j] = 1
        for x in [-1, 0, 1]:
            if w[2-i][j+x] == 1:
                c += 1
    else:
        w[i-1][j] = 0
        for x in [-1, 0, 1]:
            if w[2-i][j+x] == 1:
                c -= 1
    if c == 0:
        print('Yes')
    else:
        print('No')