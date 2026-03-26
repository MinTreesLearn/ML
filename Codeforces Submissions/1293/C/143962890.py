n, q = map(int, input().split())
arr = [[0 for i in range(n)] for j in range(2)]
pair = 0
while q:
    x, y = map(int, input().split())
    add = 0
    x -= 1
    y -= 1
    if arr[x][y] == 1:
        arr[x][y] = 0
        add = -1
    else:
        arr[x][y] = 1
        add = 1
    for i in range(-1, 2):
        if i + y >= 0 and i + y < n and arr[1 - x][y + i] == 1:
            pair += add
    if pair == 0:
        print("Yes")
    else:
        print("No")
    q -= 1
