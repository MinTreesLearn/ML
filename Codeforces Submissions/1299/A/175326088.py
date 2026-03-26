import random
def transformare_baza(numar,baza):
 
 
 vector_transformare=[0]*40
 
 transformare=""
 while numar>=baza:
  rest=numar%baza
  numar=numar//baza
  transformare+=str(rest)
  
 
 transformare+=str(numar)
 noua_baza=transformare[::-1]
 
 nou_string=(40-len(noua_baza))*'0'
 noua_baza=nou_string+noua_baza
 
 for j in range(40):
  vector_transformare[j]=noua_baza[j]
 
 return noua_baza

def bitwise_xor(a,b):
 stringul_1=transformare_baza(a,2)
 stringul_2=transformare_baza(b,2)
 
 lungime=max(len(stringul_1), len(stringul_2))
 raspunsul=0
 #print(stringul_1,stringul_2)
 
 str_answ=[0]*40
# print('lungime=', lungime)
 
 #print(str_answ)
 
 for i in range(0,lungime):
 # print(i,str_answ)
  j=lungime-1-i
  if len(stringul_1)>i and len(stringul_2)>i:
   if stringul_1[len(stringul_1)-1-i]!= stringul_2[len(stringul_2)-1-i]:
    raspunsul+=2**(i)
    str_answ[39-i]='1'
  elif len(stringul_1)>i and stringul_1[len(stringul_1)-1-i]=='1':
   raspunsul+=2**(i)
   str_answ[39-i]='1'
  elif len(stringul_2)>i and stringul_2[len(stringul_2)-1-i]=='1':
   raspunsul+=2**(i)
   str_answ[39-i]='1'
   
 #print(str_answ)
 str_answ=str_answ[::-1]
 
 return str_answ

def bitwise_or(a,b):
 stringul_1=transformare_baza(a,2)
 stringul_2=transformare_baza(b,2)
 
 lungime=max(len(stringul_1), len(stringul_2))
 raspunsul=0
 #print(stringul_1,stringul_2)
 
 str_answ=[0]*40
# print('lungime=', lungime)
 
 #print(stringul_1,stringul_2)
 
 #print(str_answ)
 #print("l1=",len(stringul_1), "l2=",len(stringul_2))
 for i in range(0,lungime):
 # print(i,str_answ)
  j=lungime-1-i
  #print(i,"aici?",stringul_2[len(stringul_2)-1-i])
  
  if len(stringul_1)>i and len(stringul_2)>i:
   
   if stringul_1[len(stringul_1)-1-i]!='0' or '0'!= stringul_2[len(stringul_2)-1-i]:
    
    raspunsul+=2**(i)
    str_answ[39-i]='1'
  elif len(stringul_1)>i and stringul_1[len(stringul_1)-1-i]=='1' :
   raspunsul+=2**(i)
   str_answ[39-i]='1'
  elif len(stringul_2)>i and stringul_2[len(stringul_2)-1-i]=='1' :
   raspunsul+=2**(i)
   str_answ[39-i]='1'
 
 #print("aici")  
 #print(*str_answ)
 
 return raspunsul

#n,m,k=list(map(int, input().split()))
 
#cazuri=int(input())
cate=0
care=-1

tupla=[]
 
for tt in range(1):
 matrice=[]
 n=int(input())
 bloc=list(map(int,input().split()))
 
 for i in range(n):
  matrice.append(transformare_baza(bloc[i],2))
  
 posibil=0
 care=-1
 for i in range(40):
  
  posibil=0
  partial=-1
  for j in range(n):
   if matrice[j][i]=='1' :
   # print(j,i,posibil,partial)
    if posibil==0:
     posibil=1
     partial=j
     #print("care",bloc[care],j) 
    else:
     posibil=-1
     j=n+1
     break
  if posibil==1:
   care=partial
   #print("care=",care)
   j=n+1
   i=41
   break
 
 #print("care=",care)
 #if care>-1:
#  print(bloc[care],end=' ')
#  print(*bloc[0:care],end=' ')
#  print(*bloc[care+1:n])
# else:
#  print(*bloc)
    
# print(matrice)  
  
 if care>-1:
  print(bloc[care],end=' ')
  print(*bloc[0:care],end=' ')
  print(*bloc[care+1:n])
 else:
  print(*bloc)
