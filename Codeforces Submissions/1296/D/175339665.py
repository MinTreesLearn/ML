import math
import random

#n,m,k=list(map(int, input().split()))
 
#cazuri=int(input())

n,a,b,k=list(map(int,input().split()))
bloc=list(map(int,input().split()))

#n=500000
#bloc=[]
#for z in range(n):
# bloc.append(random.randint(1,10**9))
cate=0
suma=a+b
resturi=[]

for i in range(n):
 rest=bloc[i]%suma
 
 
 if rest>0 and rest<=a:
  cate+=1
 else:
  if rest==0:
   rest=suma
  
 # print("i=",bloc[i],rest)
  
  resturi.append(math.ceil((rest-a)/a))
  
#print(resturi)
resturi.sort()
 
for j in resturi:
 if k>=j:
  cate+=1
  k-=j
 else:
  break
 
print(cate)

  
 
 