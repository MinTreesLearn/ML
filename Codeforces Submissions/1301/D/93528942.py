import sys
input=sys.stdin.readline
l=input().split()
n=int(l[0])
m=int(l[1])
k=int(l[2])
tot=2*(2*n*m-n-m)
if(k>tot):
    print("NO")
    quit()
l=[]
if(m>1):
    l.append(((m-1),'R'))
    l.append(((m-1),'L'))
if(n>1):
    l.append((1,'D'))
for i in range(n-1):
    if(m>1):
        l.append(((m-1),'R'))
        l.append(((m-1),'UDL'))
    if(i!=n-2):
        l.append((1,'D'))
    else:
        l.append((n-1,'U'))
print("YES")
lfi=[]
for i in l:
    if(i[0]*len(i[1])<=k):
        lfi.append(i)
        k-=(i[0]*len(i[1]))
    else:
        z=k//(len(i[1]))
        if(z):
            lfi.append((z,i[1]))
        y=k%(len(i[1]))
        for j in range(y):
            lfi.append((1,i[1][j]))
        break
print(len(lfi))
for i in lfi:
    print(i[0],i[1])
