start=False
counter=False
o=0
counter1=0

result=[]




for i in range(int(input())):
    start=False
    counter=False
    o=0
    counter1=0

    
    x=input()
    x=x.rstrip("0") 
    
    for j  in x: 
      if j=="0" and not(start):
          pass
      elif j=="1":
          counter=False
          start=True
      elif j=="0" and start:
          counter=True
          
          start=False
      if counter:
          counter1+=1
    result.append(counter1)
              
          
            
           
    
    
for i in result: print(i)
