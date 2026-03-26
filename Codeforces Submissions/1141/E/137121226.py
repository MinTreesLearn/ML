import sys,math,heapq,queue
fast_input=sys.stdin.readline 


h,n=map(int,fast_input().split())
d=list(map(int,fast_input().split())) 
for i in range(1,n):
    d[i]+=d[i-1]

m=min(d) 

if h+m<=0:
    for i in range(n):
        if d[i]+h<=0:
            print(i+1)
            break

elif h+d[-1]>=h:
    print(-1)
else:
    x=math.ceil((h+m)/abs(d[-1])) 
    h=h-x*abs(d[-1])
    for i in range(n):
        if h+d[i]<=0:
            print(x*n+i+1)
            break
    