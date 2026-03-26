def solve():
    n, x, y = map(int, input().split())
    if x > y:
        x, y = y, x
    hi_left = n
    if y == n:
        hi_left -= 1
    can_take = x + y - hi_left
    best = 0
    if can_take <= 0:
        best = 1
    else:
        best = can_take
        if x > can_take:
            best += 1
    worst = 0
    if x + y > n:
        worst = n
    else:
        worst = x + y - 1
    if best < 1:
        best = 1
    elif best > n:
        best = n
    if worst < 1:
        worst = 1
    elif worst > n:
        worst = n
    print(best, worst)


test = int(input())
while test:
    test -= 1
    solve()
