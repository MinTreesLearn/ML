from sys import stdin, stdout, setrecursionlimit
# from Multiset import update, remove
from bisect import bisect_left

string    = lambda: stdin.readline().strip()
get       = lambda: int(stdin.readline().strip())
array     = lambda: list(map(int, stdin.readline().strip().split()))
charar    = lambda: list(map(str, stdin.readline().strip()))
put       = lambda *args: [stdout.write(str(i)) for i in args]

mod, inf = int(1e9 + 7), int(1e15)



def solve():
    n = get()
    x = array()
    v = array()

    z = sorted(list(zip(v, x)))

    x.sort()

    s = 0
    for i in range(n) :
        s += (bisect_left(x, z[i][1]) + i - n + 1) * z[i][1]
    print(s)

solve()