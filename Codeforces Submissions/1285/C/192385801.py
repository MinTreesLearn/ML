def helper(l,i,t,x):
    global ans,lans
    if i>=len(l):
        return
    if max(t,x)<ans:
        ans=max(t,x)
        lans[0]=t
        lans[1]=x
    helper(l,i+1,t*l[i],x//l[i])
    helper(l,i+1,t,x)

n=int(input())
l=[]
t=n
i=1
while t%2==0:
    i*=2
    t//=2
l.append(i)
j=3
while j*j<=t:
    i=1
    if t%j==0:
        while (t%j==0):
            t//=j
            i*=j
        l.append(i)
    j+=2
if (t>2):
    l.append(int(t))
lans=[0,0]
ans=999999999999
helper(l,0,1,n)
print(*lans)