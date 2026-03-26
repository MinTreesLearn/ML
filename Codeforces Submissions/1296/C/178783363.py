for _ in range(int(input())):
    n = int(input())
    s = input()
    d = dict()
    d[(0, 0)] = 0
    x, y = 0, 0
    l, r = -1, n
    for i, c in enumerate(s):
        x += (1 if c == 'R' else 0) - (1 if c == 'L' else 0)
        y += (1 if c == 'U' else 0) - (1 if c == 'D' else 0)
        if (x, y) in d:
            if i - d[(x, y)] + 1 < r - l + 1:
                l, r = d[(x, y)], i
        d[(x, y)] = i+1
    if l == -1:
        print(-1)
    else:
        print(l+1, r+1)
