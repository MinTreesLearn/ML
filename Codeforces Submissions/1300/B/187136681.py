t = int(input())

for i in range(t):
    n =  int(input())
    ll = list(map(int,input().split()))
    ll = sorted(ll,reverse=True)

    l1 = []
    l2 = []
    if n%2 == 0:
        l1len = n+1
        l2len = n-1
    else:
        l1len = n
        l2len = n
    for i in range(len(ll)):
        if i % 2 == 0 and len(l1) < l1len:
            l1.append(ll[i])
        elif len(l2) < l2len:
            l2.append(ll[i])
        else:
            l1.append(ll[i])
    print(abs(l1[len(l1)//2] - l2[len(l2)//2]))