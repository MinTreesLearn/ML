import itertools

for t in range(int(input())):
    n = int(input())

    a = list(itertools.accumulate(map(int, input().split())))

    if min(a[:-1]) <= 0 or max(a[:-1]) >= a[-1]:
        print('NO')
    else:
        print('YES')
