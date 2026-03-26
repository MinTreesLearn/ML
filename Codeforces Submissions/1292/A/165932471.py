n, q = map(int, input().split())

lava = [[0 for i in range(n)] for j in range(2)]

blocked = 0
for i in range(q):
    r, c = map(lambda x: int(x)-1, input().split())

    delta = 1 if lava[r][c] == 0 else -1
    lava[r][c] = 1 - lava[r][c]

    ri = 0 if r == 1 else 1
    for j in [-1, 0, 1]:
        ci = c + j
        if 0 <= ci < n:
            if lava[ri][ci] == 1 and lava[r][c] == 0:
                blocked = blocked + delta
            elif lava[ri][ci] == lava[r][c] == 1:
                blocked = blocked + delta

    if blocked == 0:
        print('Yes')
    else:
        print('No')
