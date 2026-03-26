n = int(input())
l = list(map(int,input().split()))
ans = [0] 
for i in range (n-1):
    ans.append(ans[-1]+l[i])
a = min(ans)
for i in range(n):
    ans[i] = ans[i] - a + 1
a = [False for i in range (n)]
for i in range(n):
    if ans[i] <= n: a[ans[i]-1] = True
bb = True
for i in range(n):
    bb = bb and a[i]
if bb:
    for i in ans:
        print(i, end = " ")
else:
    print(-1)