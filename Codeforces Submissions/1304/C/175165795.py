row1 = int(input())
for r1 in range(row1):
    l1 = input().split(' ')
    row2 = int(l1[0])
    tem = int(l1[1])
    a = tem
    b = tem
    t1 = 0
    state = 0
    for r2 in range(row2):
        l2 = input().split(' ')
        t2 = int(l2[0])
        c = int(l2[1])
        d = int(l2[2])
        a = a+t1-t2
        b = b+t2-t1
        if a <= d and b >= c:
            a = max(a,c)
            b = min(b,d)
            t1 = t2
        else:
            state = 1
    if state == 1:
        print("NO")
    else:
        print("YES")

