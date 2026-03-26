for _ in range(int(input())):
    n,g,b=map(int,input().split())
    if n%2==0:
        k=int(n/2)
    else:
        k=int(n/2)+1
    if k%g==0:
        x=int(k/g)
    else:
        x=int(k/g)+1
    ans=(x-1)*b+(x-1)*g
    gleft=k-(x-1)*g
    ans+=gleft
    if ans>=n:
        print(ans)
    else:
        print(n)