import math
 
 
def functie_divizori(numar):
 
 
 dictionar={}
 
 matrice=[]
 if numar==1:
  a=[1]*2
  a.append(0)
  a.append(0)
  matrice.append(a)
 else: 
  for j in range(1,math.floor(numar**(1/2))+1):
  # print("j=",j)
   
   if numar%j==0:
    tupleta=[]
  #  print(dictionar)
    
 
     
 
     
     
    tupleta.append(j)
    tupleta.append(numar//j)
    tupleta.append(0)
    tupleta.append(0)
    matrice.append(tupleta)
    tupleta=[]
    
    if numar//j!=j:
     tupleta=[]
     tupleta.append(numar//j)
     tupleta.append(j)
     tupleta.append(0)
     tupleta.append(0)
   
  
     matrice.append(tupleta)
 return matrice
 
n,m,k=list(map(int, input().split()))
 
#cazuri=int(input())
 
vector_a=list(map(int,input().split()))
vector_b=list(map(int,input().split()))
 
#print(functie_divizori(2))
 
 
#n=int(input())
#n,m=list(map(int,input().split()))
#bloc=list(map(int, input().split()))
#bloc.sort()
# bloc=bloc[::-1]
#print(functie_divizori(9))
 
tupleta_a=functie_divizori(k)
#tupleta_b=functie_divizori(k)
 
#print("aa",tupleta_a)
 
suma_a=0
suma_b=0
 
for i in range(n):
 if vector_a[i]==1:
  suma_a+=1
 
 else:
#  print("i=",i)
  for jj in range(len(tupleta_a)):
   if tupleta_a[jj][0]<=suma_a:
    tupleta_a[jj][2]=tupleta_a[jj][2]+suma_a+1-tupleta_a[jj][0]
  suma_a=0  
 
 
  
#print("l=",len(tupleta_a))
if suma_a>0: 
 for jj in range(len(tupleta_a)):
    #print("jj=",jj)
    if tupleta_a[jj][0]<=suma_a:
     tupleta_a[jj][2]=tupleta_a[jj][2]+suma_a+1-tupleta_a[jj][0]
   
   
    
for i in range(m):
 if vector_b[i]==1:
  suma_b+=1
 
 else:
 # print("i=",i)
  for jj in range(len(tupleta_a)):
   if tupleta_a[jj][1]<=suma_b:
    tupleta_a[jj][3]=tupleta_a[jj][3]+suma_b+1-tupleta_a[jj][1]
  suma_b=0
  
if suma_b>0:  
 for jj in range(len(tupleta_a)):
  if tupleta_a[jj][1]<=suma_b:
   tupleta_a[jj][3]=tupleta_a[jj][3]+suma_b+1-tupleta_a[jj][1]
 
   
answ=0
for i in range(len(tupleta_a)):
 answ+=tupleta_a[i][2]*tupleta_a[i][3]
# answ+=tupleta_b[i][2]*tupleta_b[i][3]
#print(tupleta_a) 
#print(tupleta_b) 
print(answ)