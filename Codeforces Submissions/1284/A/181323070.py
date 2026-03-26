import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
s = list(input().rstrip().decode().split())
t = list(input().rstrip().decode().split())
q = int(input())
ans = []
for _ in range(q):
    y = int(input())
    ans0 = s[(y - 1) % n] + t[(y - 1) % m]
    ans.append(ans0)
sys.stdout.write("\n".join(ans))