n,k=list(map(int,input().split()))
a=[input() for i in range(n)]
b=set(a)

E=ord("S")+ord("E")+ord("T")

d=0
for i in range(n-1):
    for j in range(i+1,n):
        c=''
        for l in range(k):
            if a[i][l]==a[j][l]:
                c=c+a[i][l]
            else:
                c=c+chr(E-ord(a[i][l])-ord(a[j][l]))
        if c in b:
            d=d+1

print(d//3)