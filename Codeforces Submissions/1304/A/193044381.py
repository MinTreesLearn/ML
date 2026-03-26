# LUOGU_RID: 101845249
for _ in range(int(input())):
    x, y, a, b = map(int, input().split())
    q, r = divmod(y - x, a + b)
    print(-1 if r else q)