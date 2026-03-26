for _ in range(int(input())):
    n,m,k = list(map(int,input().split()))
    l = list(map(int,input().split()))
    mi = 0
    for i in range(min(k,m-1)+1):
        temp = 100000000000
        for j in range(m - min(k,m-1)):
            temp = min(temp , max(l[i+j] ,l[n-m+i+j] ))
        mi = max(mi,temp)
    print(mi)   