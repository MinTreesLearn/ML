t=list(map(int,input().split(" ")))
p=int(t[2])
a=list(map(int,input().split(" ")))
b=list(map(int,input().split(" ")))
ans=0
t=0
for i in a:
    if i%p!=0:
        ans+=t
        break
    t+=1
t=0
for i in b:
    if i%p!=0:
        ans+=t
        break
    t+=1
print("%d"%(ans))