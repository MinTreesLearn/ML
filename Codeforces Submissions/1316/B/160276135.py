#I = lambda: [int(i) for i in input().split()]
#import io, os, sys
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline


# n = int(input())
# l1 = list(map(int,input().split()))
# n,x = map(int,input().split())
# s = input()
#mod = 1000000007
# print("Case #"+str(_+1)+":",)

from collections import Counter,defaultdict
import sys
import math
#import bisect
                    
                
for _ in range(int(input())):
    n = int(input())
    l = list(input())
    x =  min(l)
    a = []
    for i in range(1,n):
        if l[i]==x:
            a.append(i)
    ans = l
    ans1 = 1
    for i in a:
        k = i+1
        if (n-k+1)&1:
            t = l[:i]
            t.reverse()
            temp = l[i:]+t
        else:
            temp = l[i:]+l[:i]
        if temp<ans:
            ans = temp
            ans1 = k
    print(''.join(i for i in ans))
    print(ans1)
    
                    
                    
        


        
    
