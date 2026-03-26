g = dict()
n = int(input())
a = list(map(int,input().split()))
for i in range(n):
    total = 0
    for j in range(i,n):
        total += a[j]
        if total in g:
            g[total].append((i + 1,j + 1))
        else:
            g[total] = [(i+1,j+1)]
ans = 0
res = []
for k in g:
    t = -1
    temp = 0
    li = []
    for l,r in g[k]:
        if l > t:
            temp += 1
            li.append((l,r))
            t = r
        elif t > r:
            li[-1] = (l,r)
            t = r
    if temp > ans:
        ans = temp
        res = li
print(ans)
for i in res:
    print(*i)