for i in range(int(input())):
    n = int(input())
    b = list(map(int , input().split()))
    dic = {}
    l = []
    for j in range(1 , 2*n+1):
        dic[j] = 1
    for j in range(n):
        dic[b[j]] = 0
    for j in range(n):
        l.append(b[j])
        # print(b[j] ,end= " ")
        dic[b[j]]=0
        for k in dic:
            if k > b[j] and dic[k]!=0:
                # print(k , end=" ")
                l.append(k)
                dic[k]=0
                break
    if len(l)==2*n:
        print(*l)
    else:
        print(-1)
    # print(dic)
    