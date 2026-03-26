import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    ans.append(" ".join(map(str, a)))
    ans.append(" ".join(map(str, b)))
sys.stdout.write("\n".join(ans))