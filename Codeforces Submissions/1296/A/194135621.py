
t = int(input())
for i in range(t):
    n = int(input())
    A = list(map(int,input().split()))
    ans = 0 
    ce = 0 
    co = 0
    for i in A:
        if(i&1):
            co+=1 
        else:
            ce+=1 
        
        ans = (i&1)^ans 
    if ce == n:
        print("NO")
    elif not ans and co == n:
        print("NO")
    else:
        print("YES")
    
    

 	 	  			   	 					   	 	 			