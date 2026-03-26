n,m,p=map(int,input().split())
f=list(map(int,input().split()))
g=list(map(int,input().split()))
an=0
an2=0
for i in range(n):
    if f[i]%p!=0:
        an=i
        break

for i in range(m):
    if g[i]%p!=0:
        an2=i
        break
print(an+an2)
