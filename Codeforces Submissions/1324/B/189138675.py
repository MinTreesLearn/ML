t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    otv = 'NO'
    i = 0
    while i < n:
        if a.count(a[i]) == 1:
            i += 1
        elif a.count(a[i]) == 2:
            if a[i] == a[i+1]:
                i += 2
            else:
                otv = 'YES'
                break
        else:
            otv = 'YES'
            break
    print(otv)
