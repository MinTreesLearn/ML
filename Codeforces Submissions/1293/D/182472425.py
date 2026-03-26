x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
limit=2**62-1
x,y=[x0],[y0]
while ((limit-bx)/ax>=x[-1] and (limit-by)/ay>=y[-1]):
    x.append((ax*x[-1]+bx))
    y.append((ay*y[-1]+by))
n=len(x)
ans=0
for i in range(n):
    for j in range(i,n):
        length=x[j]-x[i]+y[j]-y[i]
        dist2left=abs(xs-x[i])+abs(ys-y[i])
        dist2right=abs(xs-x[j])+abs(ys-y[j])
        if length<=t-dist2left or length<=t-dist2right:
            ans=max(ans,j-i+1)
print(ans)