def pp(a,b,c):
    i=0 
    j=1000000000
    while i<=j:
        # if b==-3:
        m=(i+j)//2 
        x=b+m*c 
        # print(i,j,x,a,b,c)
        if x==a:
            return True 
        if x>a:
            if c>0:
                j=m-1 
            else:
                i=m+1 
        else:
            if c>0:
                i=m+1 
            else:
                j=m-1 
    return False 
            

def ss(n,x,s):
    ans=0 
    a=s.count('0')
    b=n-a
    
    p=0
    q=0 
    for i in s:
        if i=='0':
            p+=1 
        else:
            q+=1
        if a==b and p-q==x:
            return -1
        if pp(x,p-q,a-b):
            # print(p,q)
            # break
            ans+=1 
            
    if x==0:
        if a==b:
            return -1
        ans+=1
    
    return ans
            

for _ in range(int(input())):
    n,x=map(int, input().split())
    s=str(input())
    
    print(ss(n,x,s))