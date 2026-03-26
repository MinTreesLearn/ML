a = int(input())
for i in range(a):
    q = int(input())
    *s, = map(int, input().split(' '))
    d = 0
    for j in range(q):
        if s[j] == 0:
            d += 1
            s[j] = 1
    if sum(s) == 0:
        d += 1
    print(d)
