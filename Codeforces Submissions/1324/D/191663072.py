from bisect import bisect
from operator import sub
def get(f): return f(input().strip())
def gets(f): return [*map(f, input().split())]


n = get(int)
a = gets(int)
b = gets(int)
d = sorted(map(sub, a, b))
s = 0
for i, v in enumerate(d):
    s += n - bisect(d, -v, i + 1)
print(s)
