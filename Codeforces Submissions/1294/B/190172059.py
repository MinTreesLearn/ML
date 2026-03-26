t=int(input())
for i in range(t):
    n=int(input())
    xp=[]
    yp=[]
    for j in range(n):
        x,y=[int(k) for k in input().split()]
        xp.append(x)
        yp.append(y)
    s=set(xp)
    ans=""
    posx=0
    posy=0
    flag=True
    for z in s:
        l=[]
        for y in range(n):
            if xp[y]==z:
                l.append(yp[y])
        l.sort()
        if min(l)<posy:
            flag=False
            break
        else :
            ans+=("R"*(z-posx))
            ans+=("U"*(max(l)-posy))
            posx=z
            posy=max(l)
    if flag==True:
        print("YES")
        print(ans)
    else :
        print("NO")