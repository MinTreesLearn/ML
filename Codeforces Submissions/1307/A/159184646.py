for _ in range(int(input())):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    total = arr[0]
    i = 1
    while d > 0 and i < n:
        new = min(d//i, arr[i])
        total += new
        d = d - (new * i)
        i += 1
    print(total)