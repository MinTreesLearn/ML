import sys, random
input = lambda : sys.stdin.readline().rstrip()


write = lambda x: sys.stdout.write(x+"\n"); writef = lambda x: print("{:.12f}".format(x))
debug = lambda x: sys.stderr.write(x+"\n")
YES="Yes"; NO="No"; pans = lambda v: print(YES if v else NO); INF=10**18
LI = lambda : list(map(int, input().split())); II=lambda : int(input()); SI=lambda : [ord(c)-ord("a") for c in input()]
def debug(_l_):
    for s in _l_.split():
        print(f"{s}={eval(s)}", end=" ")
    print()
def dlist(*l, fill=0):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [dlist(*ll, fill=fill) for _ in range(l[0])]

# 標準出力による質問 interactive
TEST = 0
import sys
def _q(l,r):
    if l>=r:
        return []
    print("?", l+1, r)
    sys.stdout.flush()
    res = []
    for i in range((r-l)*(r-l+1)//2):
        v = SI()
        res.append(v)
    return res
def answer(v):
    print(f"! {v}")
    sys.stdout.flush()
n = int(input())
if TEST:
    import random
#     random.seed(0)
    _a = [random.randint(0,25) for _ in range(n)]
    def _q(l,r):
        if l>=r:
            return []
        res = []
        for i in range(l,r):
            for j in range(i+1,r+1):
                res.append(_a[i:j])
#         print(l,r,res)
        return res
def sub(n):
    res = _q(0,n)
    count = [[0]*26 for _ in range(n+2)]
    for s in res:
        for v in s:
            count[len(s)][v] += 1
    vs = [[] for _ in range((n+1)//2)]
    for i in range((n+1)//2):
        cur = [0]*26
        for v in range(26):
            cur[v] += count[1][v]*(i+2) - count[i+2][v]
        for j in range(i):
            for v in vs[j]:
                cur[v] -= (i-j+1)
        for v in range(26):
            if cur[v]:
                vs[i].extend([v]*cur[v])
        assert len(vs[i])<=2, (i, vs[i], cur)
    return vs
vs = sub(n)
vs2 = sub(n-1)
res = _q(n-1,n)
val = res[0][0]
ans = [0]*n
ans[n-1] = val
u = n-1
for i in range(n-1):
    if i%2==0:
        vs[n-1-u].remove(ans[u])
        val = vs[n-1-u][0]
        u = n-1-u
        ans[u] = val
    else:
        vs2[u].remove(val)
        val = vs2[u][0]
        u = n-2-u
        ans[u] = val
if TEST:
    assert ans==_a
answer("".join([chr(v+ord("a")) for v in ans]))