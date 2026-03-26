import sys, random
input = lambda : sys.stdin.readline().rstrip()


write = lambda x: sys.stdout.write(x+"\n"); writef = lambda x: print("{:.12f}".format(x))
debug = lambda x: sys.stderr.write(x+"\n")
YES="Yes"; NO="No"; pans = lambda v: print(YES if v else NO); INF=10**18
LI = lambda : list(map(int, input().split())); II=lambda : int(input())
def debug(_l_):
    for s in _l_.split():
        print(f"{s}={eval(s)}", end=" ")
    print()
def dlist(*l, fill=0):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [dlist(*ll, fill=fill) for _ in range(l[0])]

T = II()
for ind in range(T):
    n,m = list(map(int, input().split()))
    c = LI()
    ns = [[] for _ in range(n)]
    for _ in range(m):
        u,v = LI()
        u -= 1
        v -= 1
        ns[v].append(u)
    d = {}
    for i in range(n):
        t = tuple(sorted(ns[i]))
        d.setdefault(t, []).append(i)
    ans = 0
    from math import gcd
    for k,v in d.items():
        if not k:
            continue
        val = sum((c[i] for i in v))
        ans = gcd(ans, val)
    print(ans)
    if ind==T-1:
        break
    LI()