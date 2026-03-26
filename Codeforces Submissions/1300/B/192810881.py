def get(f): return f(input().strip())
def gets(f): return [*map(f, input().split())]


for _ in range(get(int)):
    n = get(int)
    a = sorted(gets(int))
    print(a[n] - a[n - 1])
