p = int(input())
for j in range (p):
    n, x = map(int, input().split())
    s = set()
    num = 0
    for i in input().split():
        s.add(int(i))
    m = max(s)
    if x in s:
        print(1)
    else:
        if x % m == 0:
            num += x // m
        else:
            if x//m< 1:
                k = 1
            else:
                k = x//m
            num += k+1
        print(num)
