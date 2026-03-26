#z=int(input()) 
import math
 
alfabet = {'a': 1, 'b': 2,'c': 3,'d': 4,'e': 5,'f': 6,'g': 7,'h': 8,'i': 9,'j': 10,'k': 11,'l': 12,'m': 13,'n': 14,'o': 15,'p': 16,'q': 17,'r': 18,'s': 19,'t': 20,'u': 21,'v': 22,'w': 23,'x': 24,'y': 25,'z': 26}
alfabet_2={'1':"a", '2':"b", '3':"c", '4':"d", '5':"e", '6':"f", '7':"g", '8':"h", '9':"i", '10':"j", '11':"k", '12':"l", '13':"m", '14':"n", '15':"o", '16':"p", '17':"q", '18':"r", '19':"s", '20':"t", '21':"u", '22':"v", '23':"w", '24':"x", '25':"y", '26':"z"}
 
 
def transformare_baza(numar,baza):
 
 transformare=""
 while numar>=baza:
  rest=numar%baza
  numar=numar//baza
  transformare+=str(rest)
 
 transformare+=str(numar)
 noua_baza=transformare[::-1]
 return noua_baza
 
 
def functie_string_baza(stringul,baza):
 answ=0
 stringul=stringul.lower()
 lungime=len(stringul)
 for j in range(lungime):
  if stringul[j] in alfabet:
   answ+=(baza**(lungime-1-j))*(alfabet[stringul[j]]+9)
  else:
   #print("baza=",baza, lungime-1-j,j)
   answ+=(baza**(lungime-1-j))*(int(stringul[j]))
  
 return (answ)
 
from decimal import *
 
z=int(input())
for contorr in range(z):
 
 n,m,k=list(map(int, input().split()))
 
 bloc=list(map(int, input().split()))
  
 
 vector=[]
 start=0
 sfarsit=n-1
 k=min(k,m-1)
 #print("k=",k)
 dd=max(bloc)
 maximul=-1
 
 
 
 for pornire in range(0,k+1):
  vector=[]
  partialul=dd
  
#  print(minimul,pornire)
  
  vector=bloc[pornire:n-(k-pornire)]
  #print("v=",vector)
 
 
  target=m-k-1
  #print("targ=",target)
  
  for demaraj in range(0,target+1):
   
   
   last_vector=[]
   last_vector=vector[demaraj:len(vector)-(target+1-demaraj)+1]
   
   partialul=min(partialul,max(last_vector[len(last_vector)-1],last_vector[0]))
  
   
   #print(last_vector,partialul,maximul)
   
  maximul=max(maximul,partialul)  
 
  
 print(maximul) 