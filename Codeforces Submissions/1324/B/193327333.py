t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    flag = True
    for i in range(n-2):
        try:
            x = l.index(l[i],i+2)
            flag = False
            print("YES")
            break
        except:
            continue
    if flag:
        print("NO")
