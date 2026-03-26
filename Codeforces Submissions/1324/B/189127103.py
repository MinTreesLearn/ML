t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    flag = 'NO'
    k = 0
    while k < n:
        if a.count(a[k]) == 1:
            k += 1
        elif a.count(a[k]) == 2:
            if a[k] == a[k+1]:
                k += 2
            else:
                flag = 'YES'
                break
        else:
            flag = 'YES'
            break
    print(flag)