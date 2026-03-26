t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if sum(a) % 2 == 1:
        print("YES")
    elif any((a[i] - a[j]) % 2 == 1 for i in range(n) for j in range(i+1, n)):
        print("YES")
    else:
        print("NO")


