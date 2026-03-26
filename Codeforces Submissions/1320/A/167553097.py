n = int(input())
a = list(map(int, input().split()))

sol = [i-a[i] for i in range(n)]

val = {}
ans = 0
for i in range(n):
    if sol[i] not in val:
        val[sol[i]] = a[i]
    else:
        val[sol[i]] += a[i]

    ans = max(ans, val[sol[i]])

print(ans)
