# cook your dish here
import sys
input = sys.stdin.readline
t=1
#t=int(input())
for _ in range(t):
    h,n=map(int,input().split())
    d=list(map(int,input().split()))
    hh,s,ans=h,0,-1
    for i in range(n):
        hh+=d[i]
        s+=d[i]
        if hh<=0:
            ans=i+1
            break
    if ans!=-1 or hh>=h:
        print(ans)
    else:
        ans=10**18
        ss=0
        for i in range(n):
            ss+=d[i]
            m=-(h+ss)//s
            if h+ss+m*s<=0:
                ans=min(ans,m*n+i+1)
            elif h+ss+(m+1)*s<=0:
                ans=min(ans,(m+1)*n+i+1)
        print(ans)
    