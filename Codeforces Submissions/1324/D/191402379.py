n = int(input())
A = list(map(int,input().split()))

B = list(map(int,input().split()))

A2 = [0]*n 

for i in range(n):
    A2[i] = A[i] - B[i]
A2.sort()

ans = 0 
l,r= 0,n-1 

while l<r:
    if A2[l] + A2[r] <= 0:
        l+=1 
    else:
        ans += (r-l)
        r-=1
    
print(ans)



		 	  	     		   			   	   	