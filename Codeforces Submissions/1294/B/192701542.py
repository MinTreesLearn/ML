def get(f): return f(input().strip())
def gets(f): return [*map(f, input().split())]


for _ in range(get(int)):
    n = get(int)
    xy = sorted(gets(int) for _ in range(n))
    for i in range(1, n):
        if xy[i][1] < xy[i - 1][1]:
            print('NO')
            break
    else:
        print('YES')
        p = 0
        q = 0
        for x, y in xy:
            print(end='R' * (x - p) + 'U' * (y - q))
            p, q = x, y
        print()
