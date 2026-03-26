import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    w = list(map(int, input().split()))
    while 1:
        if not any(w):
            print('YES')
            break
        if sum(i%k for i in w) > 1:
            print('NO')
            break
        w = [i//k for i in w]
