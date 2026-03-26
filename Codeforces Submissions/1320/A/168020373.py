
n=int(input())
b=list(map(int,input().split()))
d={}
for i in range(n):
    if i-b[i] in d:
        d[i-b[i]].append(i)
    else:
        d[i-b[i]]=[i]
mx=0
for x in d:
    r=0
    for m in d[x]:
        r+=b[m]
    mx=max(mx,r)
print(mx)