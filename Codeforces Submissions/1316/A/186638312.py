q = int(input())
for i in range(q):
    w = input().split()
    n, m = w
    n = int(n)
    m = int(m)
    b = input().split()
    s = 0
    for j in range(len(b)):
        b[j] = int(b[j])
        s = s + b[j]
    if s > m:
        print(m)
    else:
        print(s)
