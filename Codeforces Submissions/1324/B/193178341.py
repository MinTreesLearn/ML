t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    f = False
    for j in range(n):
        for k in range(j, n):
            if a[j] == a[k] and (k - j) >= 2:
                print('YES')
                f = True
                break
        if f == True:
            break
    if f == False:
        print("NO")