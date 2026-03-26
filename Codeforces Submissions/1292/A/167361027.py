import sys
input = lambda: sys.stdin.readline().rstrip()

n, q = map(int, input().split())

cur = [[0] * n for _ in range(2)]
trouble_ups = set()

for _ in range(q):
    x, y = map(int, input().split())
    x -= 1
    y -= 1

    if x == 0:
        if cur[0][y] == 0:
            cur[0][y] = 1
            is_tr = False
            if y - 1 >= 0:
                if cur[1][y - 1]:
                    is_tr = True
            if cur[1][y]:
                is_tr = True
            if y + 1 < n:
                if cur[1][y + 1]:
                    is_tr = True
            if is_tr:
                trouble_ups.add(y)
        else:
            cur[0][y] = 0
            trouble_ups.discard(y)
    else:
        if cur[1][y] == 0:
            cur[1][y] = 1
            for ny in range(y - 1, y + 2):
                if 0 <= ny < n:
                    if cur[0][ny]:
                        trouble_ups.add(ny)
        else:
            cur[1][y] = 0
            for ny in range(y - 1, y + 2):
                if 0 <= ny < n:
                    is_freed = True
                    if cur[0][ny]:
                        for nny in range(ny - 1, ny + 2):
                            if 0 <= nny < n:
                                if cur[1][nny]:
                                    is_freed = False
                    if is_freed:
                        trouble_ups.discard(ny)

    if trouble_ups:
        print('No')
    else:
        print('Yes')