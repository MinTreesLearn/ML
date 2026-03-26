n=int(input())
d=dict()
sp=list(map(int, input().split()))
for i in range(n):
    r=sp[i]-i
    if r in d:
        d[r]+=sp[i]
    else:
        d[r]=sp[i]
print(max(d.values()))
