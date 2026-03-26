
n,m=map(int,input().split())
c=False
c=set()
rez=0
h=[]
for i in range (n):
    l=input()
    if l[::-1] in c:
        c.remove(l[::-1])
        h.append(l)
        rez+=2*m
    else:
        c.add(l)
s=rez//m//2-1
t=None
for i in c:
    if i[::-1] == i:
        rez+=m
        t=i
        break
print(rez)
for i in h:
    print(i, end="")
if t!=None:
    print(t,end="")
while s>=0:
    print(h[s][::-1],end="")
    s-=1
        
    
        