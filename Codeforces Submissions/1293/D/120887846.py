MAX=2e18
x=[]
y=[]
s=input().split(" ")
x.append(int(s[0]))
y.append(int(s[1]))
ax=int(s[2])
ay=int(s[3])
bx=int(s[4])
by=int(s[5])
while True:
    xx=x[len(x)-1]*ax+bx
    yy=y[len(y)-1]*ay+by
    if xx>MAX or yy>MAX:
        break
    x.append(xx)
    y.append(yy)
sx,sy,t=map(int,input().split())
ans=0
for i in range(0,len(x)):
    for j in range(i,len(x)):
        if min(abs(sx-x[i])+abs(sy-y[i]),abs(sx-x[j])+abs(sy-y[j]))+abs(x[i]-x[j])+abs(y[i]-y[j])<=t:
            ans=max(ans,j-i+1)
print(ans)
