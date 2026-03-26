t=int(input())
 
for k in range(t):
    nit,x,y=map(int,input().split())
    print(max(1,min(nit,x+y-nit+1)),min(x+y-1,nit))
