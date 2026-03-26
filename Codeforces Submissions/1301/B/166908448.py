for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    l=0
    h=10**9+7
    def check(x):
        res=0
        for i in range(len(arr)):
            if arr[i]==-1:
                if i>0 and arr[i-1]!=-1:
                    res=max(res,abs(arr[i-1]-x))
                if i<len(arr)-1 and arr[i+1]!=-1:
                    res=max(res,abs(arr[i+1]-x))
            else :
                
                if i<len(arr)-1 and arr[i+1]!=-1:
                    res=max(res,abs(arr[i+1]-arr[i]))
                    
        return res
                    
                    
    while l<=h:
        mid=(l+h)>>1
        if check(mid)<=check(mid+1):
            ans=mid
            h=mid-1
        else :
            l=mid+1
    print(check(ans),ans)