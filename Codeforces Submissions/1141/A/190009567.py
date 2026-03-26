n, m = [int(_) for _ in input().split()]

moves = 0

if m % n != 0:
    print(-1)
else:
    x = m//n
    while x % 2 == 0:
        x = x//2
        moves += 1
    while x % 3 == 0:
        x = x//3
        moves += 1
    if x == 1:
        print(moves)
    else:
        print(-1)
