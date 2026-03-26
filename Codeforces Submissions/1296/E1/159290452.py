from bisect import bisect_right
from collections import defaultdict
n=int(input())
s=input()
a=[0]*n
d=defaultdict(int)
ind=defaultdict(int)
for i,el in enumerate(s):
    num=200*(ord(el)-ord("a"))+d[el]
    d[el]+=1
    a[i]=num
    ind[num]=i
l=True
q=[False]*n
for i in range(n):
    m=min(a[i:])
    for j in range(n):
        if a[j]==m:
            break
        
    if i==j:
        if q[ind[m]]==False:
            q[ind[m]]=0
    
    elif q[ind[m]]==False:
        s=set()
        for el in a[i:j]:
            if q[ind[el]]==False:
                pass
            else :
                s.add(q[ind[el]])
        if len(s)>1:
            l=False
        elif len(s)==0:
            q[ind[m]]=0
            for el in a[i:j]:
                q[ind[el]]=1
        else :
            val=list(s)[0]
            for el in a[i:j]:
                q[ind[el]]=val
            q[ind[m]]=(val+1)%2
        a=a[:i]+[m]+a[i:j]+a[j+1:]
    else :
        s=set()
        v=q[ind[m]]
        for el in a[i:j]:
            if q[ind[el]]==False:
                pass
            else :
                s.add(q[ind[el]])
        if len(s)>1:
            l=False
        elif len(s)==0:
            for el in a[i:j]:
                q[ind[el]]=(v+1)%2
        else :
            if v==list(s)[0]:
                l=False
            else:
                for el in a[i:j]:
                    q[ind[el]]=(v+1)%2
        a=a[:i]+[m]+a[i:j]+a[j+1:]
    # print(ind[m],i,j,q,a)
if not l:
    print("NO")
else :
    print('YES')
    res=""
    for el in q:
        res+=str(el)
    print(res)
                
            
            
        
        
    
    
    

            