n = int(input())
ans = list(map(int, input().split()))
ll = [0] * n
rr = [0] * n
s = 0
for i in range(n):
        s |= ans[i]
        ll[i] = s
s = 0
for i in range(n - 1, -1, -1):
        s |= ans[i]
        rr[i] = s
mx = 0
mxi = 0
for i in range(n):
        s = 0
        if i - 1 >= 0: s |= ll[i - 1]
        if i + 1 < n: s |= rr[i + 1]
        cur = (ans[i] | s) - s
        if cur > mx:
            mx = cur
            mxi = i
ans[0], ans[mxi] = ans[mxi], ans[0]
print(*ans)