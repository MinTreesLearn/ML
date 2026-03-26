a,b=map(int,input().split())
if(b%a!=0):
    print(-1)
else:
    c=b//a
    i=0
    f=0
    while(c!=1):
        if(c%3==0):
            i+=1
            c=c//3
        elif(c%2==0):
            i+=1
            c=c//2
        else:
            print(-1)
            f=1
            break
    if(f==0):
        print(i)