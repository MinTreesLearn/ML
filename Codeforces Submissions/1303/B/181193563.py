for t in  range(int(input())):
    
    n,g,b=map(int,input().split())
    l=0
    h=10**19
    def check(x):
        tg=(x//(g+b))*g
        tb=(x//(g+b))*b
        x=(x%(g+b))
        if x<=g:
            tg+=x
        else:
            tg+=g
            tb+=x-g
        if tg>=(n+1)//2:
            left=n-tg
            if left<=tb and left<=(n+1)//2:
                return True
            return False
        return False

    while l<=h:
        mid=(l+h)//2
        if check(mid):
            ans=mid
            h=mid-1
        else:
            l=mid+1
    print(ans)
    