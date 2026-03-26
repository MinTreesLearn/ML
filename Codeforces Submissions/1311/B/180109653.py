for _ in range(int(input())):
    # n=int(input())
    n,m=map(int,input().split())
    # s=input().strip()
    a=list(map(int,input().split()))
    # s=list(map(int,input()))
    pos = [int(x) for x in input().split()]
    for _ in range(m):
        for x in pos:
            if a[x - 1] > a[x]:
                a[x], a[x - 1] = a[x - 1], a[x]
    print("YES" if a == sorted(a) else "NO")