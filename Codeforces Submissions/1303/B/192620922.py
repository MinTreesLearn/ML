t=int(input())+1
while t := t-1:
    n,g,b=[int(x) for x in input().split()]
 
    mid=(n+1)//2
    fb,re=mid//g,mid%g
    comb=(b*(fb-1))
    ans= 0
    if re != 0:
        comb+=b
        ans+=re
    ans=mid+comb    
    comb=n-mid-comb 
    if comb >0:
        ans+=comb
    print( ans )  