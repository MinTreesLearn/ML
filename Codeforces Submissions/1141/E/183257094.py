h,n=input().split(' ')
h=int(h)
n=int(n)
a=input().split(' ')
for i in range(n):
    a[i]=int(a[i])
sum=h
flag=False
cur=0
for i in range(n):
    if(sum<=0):
        print(i)
        exit(0)
    sum+=a[i]
    cur+=a[i]
if(sum>=h):
    print(-1)
    exit(0)
sum=cur
l=0
r=1000000000008
ans=2**100
while(l<=r):
    mid=l+(r-l)//2
    now=h+mid*cur
    flag=False
    for i in range(n):
        if(now<=0):
            ans=min(ans,mid*n+i)
            flag=True
            break
        now+=a[i]
    if(flag):
        r=mid-1
    else:
        l=mid+1
if(ans==2**100):
    ans=-1
print(ans)
            