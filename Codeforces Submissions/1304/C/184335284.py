q=int(input())
for i in range(q):
    n, m=[int(k) for k in input().split()]
    rho=[m, m]
    last=0
    c=[]
    for j in range(n):
        c.append([int(k) for k in input().split()])
    for j in range(n):
        w=c[j]
        t=w[0]-last
        rho=[rho[0]-t, rho[1]+t]
        if rho[0]>w[2] or rho[1]<w[1]:
            print("NO")
            break
        else:
            rho=[max(rho[0], w[1]), min(rho[1], w[2])]
            last=w[0]
            #print(rho, t)
    else:
        print("YES")