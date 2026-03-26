T = 1
for test_no in range(T):
    n, q = map(int, input().split())
    lava = [[0 for j in range(n)] for i in range(2)]

    blockedPair = 0
    while q > 0:
        q -= 1
        x, y = map(lambda s: int(s) - 1, input().split())
        delta = +1 if lava[x][y] == 0 else -1

        lava[x][y] = 1 - lava[x][y]
        for dy in range(-1, 2):
            if 0 <= y + dy < n and lava[1 - x][y + dy] == 1:
                blockedPair += delta

        if blockedPair == 0:
            print('Yes')
        else:
            print('No')