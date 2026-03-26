t = int(input())
while t:
    n = int(input())
    a = [int(x) for x in input().split()]
    a = sorted(a)
    a = [a[i] - a[i-1] for i in range(1,len(a))]
    res = any((aa %2) != 0 for aa in a)
    print("NO" if res else "YES")
    t -= 1