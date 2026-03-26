t = int(input())
for _ in range(t):
    n, s, k = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(0, k+1):
        if s-i >= 1 and not s-i in a:
            print(i)
            break
        if s+i <= n and not s+i in a:
            print(i)
            break
    else: assert(False)
