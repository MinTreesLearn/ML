import math
import random



cazuri=int(input())
for jj in range(cazuri):
 
 #n=int(input())
 n,t_initial=list(map(int,input().split()))
 #bloc=list(map(int,input().split()))
 
 max_left=t_initial
 max_right=t_initial
 
 timpul_initial=0
 
 posibil_total="YES"
 
 vector=[]
 contor=-1
 s=''
 s=str(n)+"|"+str(t_initial)+"||"
 partial=1
 for pp in range(n):
  posibil=0
  bloc=list(map(int,input().split()))
  #if jj==1 and cazuri==2 :
   #for h in bloc:
   # s+=str(h)+"|"
 #  s+="||"
    
  if pp>0:
   
    
   if vector[contor][0]==bloc[0]:
    left=max(vector[contor][1],bloc[1])
    right=min(vector[contor][2],bloc[2])
    if left>right:
     partial=0
    else:
     vector[contor][1]=left
     vector[contor][2]=right
   else:
    vector.append(bloc)
    contor+=1
  else:
   vector.append(bloc)
   contor+=1
 
 
  
 if partial==0:
  print("NO")
 else:
 # print(vector)
  for pp in vector:
   posibil=0
   ti,li,hi=pp
  # print(ti,li,hi)
   
   durata=ti-timpul_initial
   timpul_initial=ti
   
   max_left=max_left-durata
   max_right=max_right+durata
   
   if (li>=max_left and li<=max_right) or (hi>=max_left and hi<=max_right) or (li<=max_left and hi>=max_right):
    posibil=1
    max_left=min(max(li,max_left),max_right)
    max_right=max(min(hi,max_right),max_left)
   if posibil==0:
    posibil_total="NO"
    break
   
   
  print(posibil_total)
 