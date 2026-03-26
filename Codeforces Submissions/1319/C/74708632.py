n=int(input())
f=input()
d=set()
for i in f:
    d.add(i)
d=sorted(list(d))
x = len(d)
count=0
x1=len(f)
i=x-1
while i>=0:
    flag=0
    if count +1 == x1:
        break
    ut=0
    rty=x1-1-count
    for j in range(1, rty):
        if f[j-ut]==d[i] and (ord(f[j-ut])-ord(f[j-1-ut])==1 or ord(f[j-ut])-ord(f[j+1-ut])==1):
            count+=1
            f=f[:j-ut]+f[j+1-ut:]
            ut+=1
            flag=1
    if f[0]==d[i] and ord(f[0])-ord(f[1])==1:
        count+=1
        f=f[1:]
        flag=1
    if f[-1]==d[i] and ord(f[-1])-ord(f[-2])==1:
        count+=1
        flag=1
        f=f[:-1]
    i-=1
    i+=flag
print(count)
