def get(f): return f(input().strip())
def gets(f): return [*map(f, input().split())]


for _ in range(get(int)):
    n = get(int)
    s = 0
    z = 0
    for a in gets(int):
        s += (not a) + a
        z += not a
    print((not s) + z)
