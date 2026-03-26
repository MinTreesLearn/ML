t = int(input())
for _ in range(t):
    m,n = map(int,input().split())
    l = list(map(int,input().split()))
    p = list(map(int,input().split()))
    p.sort()
    d,c = 0,0
    for i in range(n-1):
        if p[i]+1 == p[i+1]:
            if c == 0:
                x = p[i]
                y = p[i+1]
                c = 1
            else:
                y = p[i+1]
            d = 1
        else:
            if d == 0:
                x,y = p[i],p[i]
            l[x-1:y+1] = sorted(l[x-1:y+1])
            d,c = 0,0
    if d == 1:
        l[x-1:y+1] = sorted(l[x-1:y+1])

    l[p[n-1]-1 : p[n-1]+1] = sorted(l[p[n-1]-1 : p[n-1]+1])
    c = 0
    for i in range(m-1):
        if l[i]>l[i+1]:
            c=1
            break
    if c==1:
        print("NO")
    else:
        print("YES")
            
    
     
    

