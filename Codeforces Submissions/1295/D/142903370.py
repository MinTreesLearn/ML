import io,os
import math 
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

MAX = 100001
prime = [0]*(MAX+1)

for i in range(2,MAX+1):
    if prime[i]>1: continue
    for j in range(i,MAX+1,i):
        prime[j] += 1


primelist = []
for i in range(2,MAX+1):
    if prime[i]==1:  primelist.append(i)



def factorize(num):

    pf = []
    for p in primelist:
        if num%p>0: continue
        count = 0 
        while num%p==0:
            num = num//p
            count += 1
        pf.append(p)

    if num>1:  pf.append(num)
    return pf
        




def main(t):



    a,m = map(int,input().split())

    g = math.gcd(a,m)
    a = a//g
    m = m//g


    pf = factorize(m)
#    print(pf)


    tot = 1


    ans = m
   
    for b in range(1,1<<len(pf)):
#        print(b,"*")
        num = 1
        sym = 1
        
        for i in range(len(pf)-1,-1,-1):
            num *= pow(pf[i], b%2 )
            if b % 2==1:  sym *= (-1)
            b = b//2


        count = (a+m-1)//num - (a-1)//num
#        print(sym,count,num)
        ans += sym * count 

    print(ans)
        
    




          
        
    
    

























T = int(input())
t = 1
while t<=T:
    main(t)
    t += 1
