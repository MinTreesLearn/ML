T = int(input())
for _ in range(T):
    n, x = map(int, input().split(' '))
    ls = sorted(list(map(int, input().split(' '))))
    if x in ls:
        print(1)
    elif ls[-1] > x:
        print(2)
    else:
        print((x + ls[-1] - 1) // ls[-1])
