n, q = map(int, input().split())

m = [[0 for _ in range(n)], [0 for _ in range(n)]]
blocked = 0

for _ in range(q):
    r, c = map(int, input().split())
    r = r - 1
    c = c - 1
    
    row_to_check = (r + 1) % 2
        
    if c == 0:
        columns_to_check = [c, c + 1]
    elif c == n - 1:
        columns_to_check = [c - 1, c]
    else:
        columns_to_check = [c - 1, c, c + 1]

    m[r][c] = (m[r][c] + 1) % 2

    for column_to_check in columns_to_check:
        if m[row_to_check][column_to_check] == 1:
            if m[r][c]:
                blocked += 1
            else:
                blocked -= 1

    print('Yes' if blocked <= 0 else 'No')
