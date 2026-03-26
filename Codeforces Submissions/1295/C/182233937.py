#z=int(input()) 
import math
from itertools import combinations
import time
import random
 
def transformare_baza(numar,baza):
 
 transformare=""
 while numar>=baza:
  rest=numar%baza
  numar=numar//baza
  transformare+=str(rest)
 
 transformare+=str(numar)
 noua_baza=transformare[::-1]
 return noua_baza
 
 
def bitwise_or(a,b):
 stringul_1=transformare_baza(a,2)
 stringul_2=transformare_baza(b,2)
 
 lungime=max(len(stringul_1), len(stringul_2))
 raspunsul=0
 #print(stringul_1,stringul_2)
 
 str_answ=[0]*lungime
# print('lungime=', lungime)
 
 #print(str_answ)
 
 for i in range(0,lungime):
 # print(i,str_answ)
  j=lungime-1-i
  if len(stringul_1)>i and len(stringul_2)>i:
   if stringul_1[len(stringul_1)-1-i]!='0' or  stringul_2[len(stringul_2)-1-i]!='0':
    raspunsul+=2**(i)
    str_answ[i]='1'
  elif len(stringul_1)>i and stringul_1[len(stringul_1)-1-i]=='1':
   raspunsul+=2**(i)
   str_answ[i]='1'
  elif len(stringul_2)>i and stringul_2[len(stringul_2)-1-i]=='1':
   raspunsul+=2**(i)
   str_answ[i]='1'
   
 #print(str_answ)
 
 return raspunsul
 
 
def bitwise_and(a,b):
 stringul_1=transformare_baza(a,2)
 stringul_2=transformare_baza(b,2)
 
 lungime=max(len(stringul_1), len(stringul_2))
 raspunsul=0
 #print(stringul_1,stringul_2)
 
 str_answ=[0]*lungime
# print('lungime=', lungime)
 
 #print(str_answ)
 
 for i in range(0,lungime):
 # print(i,str_answ)
  j=lungime-1-i
  if len(stringul_1)>i and len(stringul_2)>i:
   if stringul_1[len(stringul_1)-1-i]=='1' and  stringul_2[len(stringul_2)-1-i]=='1':
    raspunsul+=2**(i)
    str_answ[i]='1'
   else:
    str_answ[i]='0'
   
 #print(str_answ)
 
 return raspunsul
 
 
 
 
alfabet = {'a': 1, 'b': 2,'c': 3,'d': 4,'e': 5,'f': 6,'g': 7,'h': 8,'i': 9,'j': 10,'k': 11,'l': 12,'m': 13,'n': 14,'o': 15,'p': 16,'q': 17,'r': 18,'s': 19,'t': 20,'u': 21,'v': 22,'w': 23,'x': 24,'y': 25,'z': 26}
alfabet_2={'1':"a", '2':"b", '3':"c", '4':"d", '5':"e", '6':"f", '7':"g", '8':"h", '9':"i", '10':"j", '11':"k", '12':"l", '13':"m", '14':"n", '15':"o", '16':"p", '17':"q", '18':"r", '19':"s", '20':"t", '21':"u", '22':"v", '23':"w", '24':"x", '25':"y", '26':"z"}
def comparatie(a,b):
  #print("1st",a,b)
  if len(a)<=1:
   return a==b
   
  elif a[0:len(a)//2]==b[0:len(b)//2]:
   return comparatie (a[len(a)//2:len(a)],b[len(b)//2:len(b)])
  else:
   return  False
 
 
def functie(vector,suma,pozitie,cate):
 
 answ=0
 #if pozitie==2:
  #print(suma,min(cate,pozitie+1))
 if pozitie>=0:
  if suma>=vector[pozitie]:
   if pozitie+1>=cate:
    suma-=vector[pozitie]
    answ+=cate
    answ+=functie(vector,suma,pozitie-cate,cate)
  
    
   else:
    suma-=vector[pozitie]
    answ+=1
    answ+=functie(vector,suma,pozitie-1,cate)
    
   
 return answ  
 
 
 
 
def functie_string_baza(stringul,baza):
 answ=pr
 stringul=stringul.lower()
 lungime=len(stringul)
 for j in range(lungime):
  if stringul[j] in alfabet:
   answ+=(baza**(lungime-1-j))*(alfabet[stringul[j]]+9)
  else:
   #print("baza=",baza, lungime-1-j,j)
   answ+=(baza**(lungime-1-j))*(int(stringul[j]))
  
 return (answ)
 
 
#z=int(input())
 
 
tupla=[] 
dictionar={}
z=int(input())
for contorr in range(z):
 
 #n=int(input())
 stringul=input()
 target=input()
 
 #maximul=10**9+1
 
 #n,m=list(map(int, input().split()))
 #bloc=list(map(int, input().split()))
# vector=list(map(int, input().split()))
 
 
 #bloc=[]
 #vector=[]
 #n=200
 #m=200
 
 vector=[[] for x in range(27)]
 setul=set()
 
 n= len(stringul)
 
 for i in range(n):
 
  
  vector[(alfabet[stringul[i]])].append(i)
  
  setul.add(stringul[i])
  
  cate=0
  posibil=1
  pornire=0
  
 first=-1
  
 for dd in range(len(target)):
  
  #print("dd=",dd,first)
  
  i=target[dd]
  if i not in setul:
   posibil=0
   break
   
  else:
   if first==-1:
    cate+=1
    first=vector[alfabet[i]][0]
   else:
    
    if vector[alfabet[i]][len(vector[alfabet[i]])-1]>first:
     #cb
     prima= 0
     ultima=len(vector[alfabet[i]])-1
     
     pp=1
     centru=prima
     while prima+1<ultima:
      
      centru=(prima+ultima)//2
      
      while vector[alfabet[i]][centru]<=first and prima+1<ultima:
       prima=centru
       centru=(prima+ultima)//2
      while vector[alfabet[i]][centru]>first and prima+1<ultima:
       ultima=centru
       centru=(prima+ultima)//2
     
     
     if vector[alfabet[i]][centru]<=first:
      centru+=1
     first=vector[alfabet[i]][centru]
     #print("i=",i,"ff=",first,"centru=",centru)
     
    else:
     cate+=1
     first=vector[alfabet[i]][0]
    
  #print("dd=",dd,first)
  
 if posibil==0:
  print(-1)
 else: 
  print(cate) 
  #print(first)
 
     