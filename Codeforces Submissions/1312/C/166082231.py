import math
for _ in range(int(input())):
    (n, k) = tuple(map(int, input().split()))
    a = list(map(int, input().split()))
    l = []
    dct = {}
    s = math.ceil(math.log(10**16, k))
    for i in range(s, -1, -1):
        l.append(k**i)
    pos = True
    for i, item in enumerate(a):
        for j, item1 in enumerate(l):
            if item1 <= item:
                if j in dct:
                    pos = False
                else:
                    item -= item1
                    dct[j] = 0
        if item != 0:
            pos = False
    if pos:
        print('yes')
    else:
        print('no')

