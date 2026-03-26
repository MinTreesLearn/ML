a = int(input())
for i in range(a):
    q = int(input())
    *s, = map(int, input().split(' '))
    w = []
    d = False
    for j in range(q):
        if s[j] % 2 == 0:
            w = j + 1
            d = True
            break
        else:
            w.append(j + 1)
    if d:
        print(1)
        print(w - 1 + 1)
    else:
        if len(w) > 1:
            print(2)
            print(w[0], w[1])
        else:
            print(-1)
