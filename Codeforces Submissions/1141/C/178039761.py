n=int(input())
l=*map(int,input().split()),
a=[0]*n
a[0]=1-l[0]
a[1]=1
f=(n+1)*[0]
x=min(a[0],a[1])
for i in range(2,n):
    a[i]=a[i-1]+l[i-1]
    x=min(x,a[i])
x=1-x
tf=True
for i,j in enumerate(a):
    j+=x
    a[i]=j
    if j>n:
        tf=False
        break
    elif f[j]:tf=False
    else:f[j]+=1
print(*a if tf else [-1])