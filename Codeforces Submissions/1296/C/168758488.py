import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()[:-1]
    for i in ['RL', 'LR', 'UD', 'DU']:
        a = s.find(i)
        if a != -1:
            print(a+1, a+2)
            break
    else:
        c, e = 10000000, 0
        d = dict()
        x = y = 0
        for i in range(n):
            d[(x, y)] = i
            if s[i] == 'L':
                x -= 1
            elif s[i] == 'R':
                x += 1
            elif s[i] == 'U':
                y += 1
            else:
                y -= 1

            if d.get((x, y), -2) != -2 and i - d[(x, y)] < c:
                c = i - d[(x, y)]
                e = d[(x, y)]

        if c == 10000000:
            print(-1)
        else:
            print(e+1, e+c+1)
