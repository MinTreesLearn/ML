n = int(input())

for i in range (0,n):
    check = 0
    a = int(input())
    lst = list(map(int, input().split()))
    d = max(lst)
    for i in lst:
        if (d - i)%2 != 0:
            check +=1
            break
    if check != 0:
        print("NO")
    else:
        print("YES")
