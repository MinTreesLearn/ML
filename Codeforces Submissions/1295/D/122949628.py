t=int(input())
from math import gcd
def fp(x, n):
  ans=1
  while(n):
    if(n%2):
      ans*=x
    x*=x
    n//=2
  return ans
def totient(n):
  k=2
  factors=[]
  while(k*k<=n):
    cnt=0
    if(n%k==0):
      while(n%k==0):
        n//=k
        cnt+=1
      factors.append([cnt, k])
    k+=1
  if(n>1):
    factors.append([1, n])
  ans=1
  for fact in factors:
    ans*=(fp(fact[1], fact[0])-fp(fact[1], fact[0]-1))
  return ans
for i in range(t):
  a, m=map(int, input().split())
  m//=gcd(a, m)
  print(totient(m))
	  		  	 		 		 	 	 		 				    	