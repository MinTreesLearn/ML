for t in range(int(input())):
    a,b,p=map(int,input().split())
    s=input()
    n=len(s)
    
    j,rj=0,0
    pr=''
    
    for i in range(n-2,-1,-1):
        
        if s[i]!=pr:
            if s[i]=='A' and p>=a:
                p-=a
            elif s[i]=='B' and p>=b:
                p-=b
            else:
                rj=i+2
                break
            pr=s[i]
    if rj==0:
        print(1)
    else:
        print(rj)

 	 	 			 		 	 	 							 	 			