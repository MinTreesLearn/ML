def ceil(a,b):
    if a%b==0:return a//b
    return a//b+1
import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n,g,b=map(int,input().split())
    tar=ceil(n,2)
    if tar<=g:
        print(n)
    else:
        if tar%g==0:
            mnd=tar//g
            #print(mnd)
            ans=mnd*(g+b)-b
            print(max(n,ans))
        else:
            mnd=tar//g
            ans=mnd*(g+b)
            tar-=g*mnd
            #print(tar)
            ans+=tar
            print(max(n,ans))