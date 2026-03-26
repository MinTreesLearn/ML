h,n = map(int,input().split())
d= list(map(int,input().split()))
z=0
cm=0

cv=0
r=0
for i in range(n):
    h= h+d[i]
    r= r+d[i]
    if h<=0:
        cm=i+1
        z=1
        break
    if r<cv:
        cv=r
        

# print(r)  
if z==1:
    print(cm)
else:
    if r>=0:
        print(-1)
    else:
        cm= cm+n
        h= h+cv
        c= int(abs(h/r))
        
        cm= cm+n*(c-1)
        # print(cm)
        h= h+r*(c-1)-cv
        
        for i in range(n):
            h= h+d[i]
            if h<=0:
                cm+=i+1
                print(cm)
                break
            if i==n-1:
                cm= cm+n
                # print("-",cm)
                # print(h)
                for i in range(n):
                    h= h+d[i]
                    if h<=0:
                        cm+=i+1
                        print(cm)
                        break
                    if i==n-1:
                        cm=cm+n
                        for i in range(n):
                            h= h+d[i]
                            if h<=0:
                                cm+=i+1
                                print(cm)
                                break

                




