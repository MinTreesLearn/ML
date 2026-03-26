n=int(input())
qs=list(map(int,input().split()))
perm=[None for i in range(n)]

decrease=0
increase=0
diff=0
firstind=0
lastind=0
for i in range(n-1):
    q=qs[i]
    if q>0 and q>decrease: decrease=0
    else: decrease-=q
    if q<0 and -q>increase: increase=0
    else: increase+=q
    if decrease>abs(diff): 
        firstind=i+1
        diff=-decrease
    if increase>abs(diff): 
        lastind=i+1
        diff=increase
permset=set(range(1,n+1))
# print(diff)

if abs(diff)!=n-1:
    print(-1)
else:
    if diff<0:
        ind=firstind
        perm[ind]=1   
    else:
        ind=lastind
        perm[ind]=n
    permset.discard(perm[ind])
    for i in range(ind+1,n):
        perm[i]=perm[i-1]+qs[i-1]
        permset.discard(perm[i])
    for i in range(ind-1,-1,-1):
        perm[i]=perm[i+1]-qs[i]
        permset.discard(perm[i])
    if len(permset)==0:
        for num in perm:
            print(num,end=' ')
    else:
        print(-1)
    
        

        






