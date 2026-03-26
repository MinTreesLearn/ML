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

n = int(input())
a = list(map(int, input().split()))
for b in range(32)[::-1]:
    c = [[],[]]
    for v in a:
        c[v>>b&1].append(v)
    if len(c[1])==1:
        val = c[1][0]
        ans = [val]
        for v in a:
            if val==v:
                continue
            ans.append(v)
        break
else:
    ans = a
write(" ".join(map(str, ans)))