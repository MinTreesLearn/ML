#z=int(input()) 
import math

 
#z=int(input())
 

#z=int(input())
for contorr in range(1):
 
 #n=int(input())
 #stringul=input()
 #print(stringul+stringul[::-1])
 q,x=list(map(int, input().split()))
 

 
 limita=400001
 vector=[-1]*x
 answ=[0]*limita
 total=[]
 
 mex=0
 
 for jj in range(q):
  j=int(input())

  part=j%x
  
 # print("p=",part)
  vector[part]+=1
  if part+x*vector[part]<limita:
   answ[part+x*vector[part]]=1
   
  posibil=1
  while posibil==1:
   posibil=0
   if mex<limita:
    if answ[mex]!=0:
    
     mex+=1
     posibil=1
  total.append(mex)
for z in total:
 print(z)
    
    
    
    
    
    
   
  

  