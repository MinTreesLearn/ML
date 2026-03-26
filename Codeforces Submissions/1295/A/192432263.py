from math import *
def get(f): return f(input().strip())
def gets(f): return [*map(f, input().split())]


for _ in range(get(int)):
    n = get(int)
    print('7' + '1' * (n - 3 >> 1) if n & 1 else '1' * (n >> 1))
