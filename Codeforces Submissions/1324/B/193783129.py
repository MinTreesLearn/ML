for i in range(int(input())):
    flag=False
    n = int(input())
    l1 = list(map(int, input().split()))
    for j in l1:
        if l1.count(j)>1:
            a=l1.index(j)
            l1.reverse()
            b=n-l1.index(j)-1
            if b-a>1:
                flag=True
                break
    if flag:
        print("YES")
    else:
        print("NO")
