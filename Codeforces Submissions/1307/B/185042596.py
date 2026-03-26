for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    if x in a:
        print(1)
    else:
        a = sorted(a)
        i = 0
        j = len(a)-1
        f = 0
        if x%2==0:
            while i<=j:
                m = (i+j)
                if a[m]>=x//2:
                    print(2)
                    f = 1
                    break
                else:
                    i = m+1
        else:
            while i<=j:
                m = (i+j)
                if a[m]>x//2:
                    f = 1
                    print(2)
                    break
                else:
                    i = m+1

        if f == 0:
            p = 0
            i = 0
            while i<len(a) and a[i]<x:
                if x%a[i]==0:
                    p = a[i]
                i = i + 1
            if p==0:
                print((x//a[-1])+1)
            else:
                print(min(x//p,(x//a[-1])+1))


