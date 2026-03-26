n,m=list(map(int,input().split()))
q=m//n
w=0
while(m%n==0 and q%2==0):
    w+=1
    q=q//2
while(m%n==0 and q%3==0):
    w+=1
    q=q//3
if(m%n==0 and q==1):
    print(w)
else:
    print(-1)