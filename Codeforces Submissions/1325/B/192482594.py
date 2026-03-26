t = int(input())
for _ in range(t):
    n = int(input())
    *l, = map(int, input().split(' '))
    print(len(set(l)))
