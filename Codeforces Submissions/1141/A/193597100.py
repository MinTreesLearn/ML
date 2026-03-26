n, m = map(int, input().split())
is_a = True
if n == m:
    print(0)
elif n * 2 == m or n * 3 == m:
    print(1)
elif (n * 2 > m and n * 3 > m) or (m % 2 != 0 and m % 3 != 0):
    print(-1)
else:
    cnt = 0
    delenie = m // n
    while delenie != 1:
        if delenie % 2 != 0 and delenie % 3 != 0:
            is_a = False
            break
        if delenie % 3 == 0:
            delenie //= 3
            cnt += 1
        else:
            delenie //= 2
            cnt += 1
    if is_a and m % n == 0:
        print(cnt)
    else:
        print(-1)