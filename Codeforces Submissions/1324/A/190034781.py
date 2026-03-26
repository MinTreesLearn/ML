def gcd(a,b):
    if(b==0):
        return a 
    else:
        return gcd(b,a%b) 
    
        
from collections import Counter 
import math
for _ in range(int(input())):
    n = int(input())
    #n,m = map(int,input().split())
    l = list(map(int,input().split()))
    x = []
    for i in range(n):
        x.append(l[i]%2) 
    
    if(len(set(x))==1):
        print("YES")
    else:
        print("NO")