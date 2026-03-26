def f(x):
    y=str(x+1)
    return y


s=list(input())
l1=[]
l2=[]
for j in range(len(s)):
    if s[j]=="(":
        l1.append(j)
    else:
        l2.append(j)
l2.reverse()
D=[]
c=1
k=0
while c!=0 and len(l1)*len(l2)!=0:
    k=k+1
    c=0
    L=[]
    J=[]
    for j in range(min(len(l1),len(l2))):
        if l1[j]<l2[j]:
            c=c+1
            L.append(l1[j])
            L.append(l2[j])
            J.append(j)
    if c==0:
        k=k-1
    ll1=[]
    ll2=[]
    for j in range(min(len(l1),len(l2))):
        if not j in J:
            ll1.append(l1[j])
            ll2.append(l2[j])
    l1=ll1
    l2=ll2
    L.sort()
    L=list(map(f,L))
    D.append([c, " ".join(L)])
print(k)
for x in D:
    if x[0]!=0:
        print(x[0]+x[0])
        print(x[1])

