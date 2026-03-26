t=int(input())
r=[]
for i in range(t):
    a=input()
    b=input()
    c=input()
    k=0
    for j in range(len(a)):
        if a[j]==b[j]:
            if c[j]!=a[j]:
                k=1
                break
        else:
            if c[j]!=a[j] and c[j]!=b[j]:
                k=1
                break
    if k==0:
        r.append("YES")
    else:
        r.append("NO")
for i in range(len(r)):
    print(r[i])