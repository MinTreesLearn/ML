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


class UF:
    # unionfind
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n))
        self.size = [1] * n
#         self.es = [0] * n
    def check(self):
        return [self.root(i) for i in range(self.n)]
    def root(self, i):
        inter = set()
        while self.parent[i]!=i:
            inter.add(i)
            i = self.parent[i]
        r = i
        for i in inter:
            self.parent[i] = r
        return r
    def merge(self, i, j):
        # 繋いだかどうかを返す
        ri = self.root(i)
        rj = self.root(j)
        if ri==rj:
#             self.es[ri] += 1
            return False
        if self.size[ri]>self.size[rj]:
            ri,rj = rj,ri
        self.parent[ri] = rj
        self.size[rj] += self.size[ri]
#         self.es[rj] += self.es[ri] + 1
        return True
    def rs(self):
        return sorted(set([self.root(i) for i in range(self.n)]))
n = int(input())
a = list(map(int, input().split()))
d = {}
for i in range(n):
    v = a[i]
    d.setdefault(i-v, 0)
    d[i-v] += v
print(max(d.values()))