n = int(input())
a = list(map(int, input().split()))
d = 0
m = 0
was = {0}
for i in a:
    d += i
    was.add(d)
    m = min(d, m)
q = -m+1
if was == {i for i in range(m, n-q+1)}:
    for i in a:
        print(q, end=' ')
        q += i
    print(q)
else:
    print(-1)
