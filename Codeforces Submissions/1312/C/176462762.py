R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:
 n,k=R();a=*R(),;r='YES'
 while any(a):
  if[x%k for x in a if x%k]>[1]:r='NO'
  a=[x//k for x in a]
 print(r)
			 						 		  		 	 		 	 		  		