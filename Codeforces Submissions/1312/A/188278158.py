t = int(input())
for _ in range(0, t):
    n, m = map(int, input().split())
    n, m = max(n, m), min(n, m)
    if n%m == 0:
        print("YES")
    else:
        print("NO")