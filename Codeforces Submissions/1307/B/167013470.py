T = int(input())
for _ in range(T):
    N, X = map(int, input().split())
    A = list(map(int, input().split()))
    m = max(A)
    if X in A:
        print(1)
    else:
        print(max(2, (X + m - 1) // m))
