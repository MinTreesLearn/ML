t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    l1 = []
    l2 = []
    for i in range(0, 2 * n, 2):
        l1.append(arr[i])
        l2.append(arr[i + 1])
    if n % 2 == 1:
        print(abs(l1[n // 2] - l2[n // 2]))
    else:
        a = l1
        b = l2
        x = b[0]
        y = a[0]
        a.append(x)
        b.remove(x)
        a.sort()
        b.sort()
        ans = abs(a[len(a) // 2] - b[len(b) // 2])
        a.remove(x)
        a.remove(y)
        b.append(x)
        b.append(y)
        a.sort()
        b.sort()
        ans = min(ans, a[len(a) // 2] - b[len(b) // 2])
        print(ans)