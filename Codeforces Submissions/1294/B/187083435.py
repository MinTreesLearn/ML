for t in range(int(input())):
    n = int(input())

    cord_list = []
    for i in range(n):
        x, y = map(int, input().split())
        cord_list.append((x, y))

    cord_list.sort()

    r = 0
    u = 0
    fir = 0
    sec = 0
    ans = ''
    while cord_list:
        r = abs(cord_list[0][0] - fir)
        u = abs(cord_list[0][1] - sec)

        ans += 'R' * r
        ans += 'U' * u

        if cord_list[0][0] < fir or cord_list[0][1] < sec:
            print('NO')
            break

        fir = cord_list[0][0]
        sec = cord_list[0][1]

        del cord_list[0]

    else:
        print('YES')
        print(ans)
