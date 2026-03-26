n=int(input())
l=[int(i) for i in input().split()]
d={}
for i in range(n):
    v=l[i]-i
    if(v in d):
        d[v]+=l[i]
    else:
        d[v]=l[i]
print(max(d.values()))