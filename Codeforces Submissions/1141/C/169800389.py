n = int(input()) 
a = list(map(int,input().split())) 
lst=[ ]
s = 0
flag = 0 
for i in a:
    s+=i 
    flag = min(flag,s) 
lst.append(1-flag) 
for i in range(1,n):
    lst.append(lst[-1]+a[i-1]) 
d = dict() 
for i in lst:
    d[i]=0 
xy=0 
for i in lst:
    d[i]+=1 
    if (d[i]>1):
        xy=1 
if (min(lst)<1 or max(lst)>n or xy==1):
    print(-1) 
else:

    print(*lst)

