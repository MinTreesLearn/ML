import sys
import math
from collections import Counter 
#from decimal import * 
#import random 
 
 
alfabet = {'a': 1, 'b': 2,'c': 3,'d': 4,'e': 5,'f': 6,'g': 7,'h': 8,'i': 9,'j': 10,'k': 11,'l': 12,'m': 13,'n': 14,'o': 15,'p': 16,'q': 17,'r': 18,'s': 19,'t': 20,'u': 21,'v': 22,'w': 23,'x': 24,'y': 25,'z': 26}
alfabet_2={'1':"a", '2':"b", '3':"c", '4':"d", '5':"e", '6':"f", '7':"g", '8':"h", '9':"i", '10':"j", '11':"k", '12':"l", '13':"m", '14':"n", '15':"o", '16':"p", '17':"q", '18':"r", '19':"s", '20':"t", '21':"u", '22':"v", '23':"w", '24':"x", '25':"y", '26':"z"}
 
 
 
 
 
def cautare(poz,tupleta,lungime):
 
 pornire=0
 oprire=poz-1
 
 
 centrare=(pornire+oprire)//2
 
# print("p=",pornire,"op=",oprire,"cen=",centrare)
 
 while pornire+1<oprire:
  centrare=(pornire+oprire)//2
  while tupleta[centrare][2]>tupleta[poz][1] and pornire+1<oprire:
   oprire=centrare
   centrare=(pornire+oprire)//2
   
  while tupleta[centrare][2]<=tupleta[poz][1] and pornire+1<oprire:
   pornire=centrare
   centrare=(pornire+oprire)//2
 
# print("cen=",centrare,pornire,oprire)
 if tupleta[centrare][2]>tupleta[poz][1]:
  centrare-=1
  
 else:
  if centrare+1<lungime:
   if tupleta[centrare+1][2]<=tupleta[poz][1]:
    centrare+=1
 return centrare
 
dictionar_linii={}
dictionar_coloane={}
 
z=int(input()) 
for contorr in range(z):
 # empty_line=input()
 #n=int(input())
 #n=1100
 #k=int(input())
 #n,x=list(map(int, input().split()))
 #stringul=input()
 #bloc=list(map(int, input().split()))
 #bloc=input()
 stringul=input()
 
 #if contorr==24:
  #print(stringul)
  
  
 dictionar={}
 dictionar_final={}
 minimul=0
 maximul=1
 
 my_set=[[] for i in range(27)]
 
 #print(len(stringul))
 
 if len(stringul)==1:
  print("YES")
  for z in alfabet:
   print(z,end='')
  print()
 elif len(stringul)==2:
  print("YES")
  print(stringul,end='')
  for z in alfabet:
   if z not in stringul:
    print(z,end='')
  print()
  
 if len(stringul)>2:
  first=stringul[0]
  last=stringul[1]
  dictionar_final[0]=stringul[0]
  dictionar_final[1]=stringul[1]
  
  
  my_set[alfabet[first]].append(last)
  my_set[alfabet[last]].append(first)
  
  dictionar[first]=0
  dictionar[last]=1
  
  #print(my_set)
  
  #
  posibil=1
  for j in range(2,len(stringul)): 
   if stringul[j] not in dictionar:
    if len(my_set[alfabet[stringul[j-1]]])>1:
     posibil=0
     break
    else:
     
     #print(my_set[alfabet[stringul[j-1]]])
     
     element=my_set[alfabet[stringul[j-1]]]
     
    # print("j=",j,"el=",element)
     
     pozitie=dictionar[my_set[alfabet[stringul[j-1]]][0]]
     
     pozitie_last=dictionar[stringul[j-1]]
     my_set[alfabet[stringul[j-1]]].append(stringul[j])
     my_set[alfabet[stringul[j]]].append(stringul[j-1])
     
     if pozitie<pozitie_last:
      dictionar[stringul[j]]=pozitie_last+1
      dictionar_final[pozitie_last+1]=stringul[j]
     else:
      dictionar[stringul[j]]=pozitie_last-1
      dictionar_final[pozitie_last-1]=stringul[j]
     
     minimul=min(minimul,dictionar[stringul[j]])
     maximul=max(maximul,dictionar[stringul[j]])
      
     #print(pozitie,pozitie_last,dictionar[stringul[j]])
    
   else:
    if stringul[j-1] not in my_set[alfabet[stringul[j]]]:
     if len(my_set[alfabet[stringul[j]]])>1:
      posibil=0
      break
     else:
      my_set[alfabet[stringul[j]]].append(stringul[j-1])
      if abs(dictionar[stringul[j]]-dictionar[stringul[j-1]])>1:
       posibil=0
       break
 
 # print(dictionar_final)
 
  if posibil==1:
   print("YES")
   for z in (alfabet):
    if z not in dictionar:
     print(z,end='')
   for p in range(minimul,maximul+1):
    print(dictionar_final[p],end='')
   print()
  else:
   print("NO")
  
  