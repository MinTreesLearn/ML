from math import ceil, floor
from collections import defaultdict 
 
for _ in range(1):
    
    n = int(input())
    b = list(map(int,input().split()))
    
    d = defaultdict(list)
    
    for i in range(n):
        d[b[i]-i].append(b[i])
        
    ans = -1000
    
    for key in d.keys():
        
        ans = max(ans,sum(d[key]))
        
    print(ans)