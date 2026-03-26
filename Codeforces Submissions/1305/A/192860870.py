t = int(input())
for i in range(t):
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    a.sort()
    b.sort()
    print(*a)
    print(*b)