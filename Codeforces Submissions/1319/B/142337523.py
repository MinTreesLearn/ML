n=int(input())
mas=list(map(int,input().split()))
d=dict()
for i in range(n):
    c=mas[i]-i
    if c not in d:
        d[c]=0
    d[c]+=mas[i]
print(max(d.values()))
