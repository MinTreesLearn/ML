n = int(input())
if n % 2 == 1:
    print('no')
else:
    s = []
    for i in range(n):
        x, y = list(map(int, input().split()))
        s.append([x, y])
    f = True
    for i in range(0, n // 2 - 1):
        a11 = s[i]
        a1 = s[i + 1]
        dx1 = a1[0] - a11[0]
        dy1 = a1[1] - a11[1]
        l1 = (dx1 ** 2 + dy1 ** 2) ** 0.5
        a2 = s[i + n // 2]
        a22 = s[i + n // 2 + 1]
        dx2 = a2[0] - a22[0]
        dy2 = a2[1] - a22[1]
        l2 = (dx2 ** 2 + dy2 ** 2) ** 0.5
        if dx1 == 0 or dx2 == 0:
            if dx1 == 0 and dx2 == 0 and l1 == l2:
                continue
            else:
                f = False
                break
        elif dy1 / dx1 == dy2 / dx2 and l1 == l2:
            continue
        else:
            f = False
            break
    if f:
        print('yeS')
    else:
        print('No')