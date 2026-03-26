for _ in range(int(input())):
    N,K = map(int,input().split())
    A = list(map(int,input().split()))
    check = [0]*101
    ans = 'Yes'
    for i in A:
        for b in range(61,-1,-1):
            if K**b<=i:
                i -= K**b
                check[b] += 1
        if i!=0:
            ans = "No"
            break

    for i in check:
        if i>=2:
            ans = "No"
            break
    print(ans)