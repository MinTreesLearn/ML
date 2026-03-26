import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse = True)
    s = set(a)
    if x in s:
        ans0 = 1
    elif a[0] > x:
        ans0 = 2
    else:
        ans0 = x // a[0] + min(x % a[0], 1)
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))