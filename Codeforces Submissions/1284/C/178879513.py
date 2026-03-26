n,m=map(int,input().split())
fact=[1]
for el in range(1,n+1):
    fact.append((fact[-1]*el)%m)
ans=0
for el in range(1,n+1):
    t=fact[el]
    p=fact[n-el+1]
    q=(n-el+1)
    ans=(ans+(((t*p)%m)*q)%m)%m    
print(ans)