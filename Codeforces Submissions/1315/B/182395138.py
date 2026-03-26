t=int(input());
for i in range(0,t):
    e=input().split()
    a=int(e[0])
    b=int(e[1])
    p=int(e[2])
    s=str(input())
    j=len(s)-2
    r=len(s)
    c=0
    while(j>=0):
        l=s[j]
        while(s[j]==l and j>=0):
            j-=1
        if(l=='A'):
            c+=a
        else:
            c+=b
        if(p>=c):
            r=j+2
    print(r)
			 	 					 	 		 	 	 	     	 		