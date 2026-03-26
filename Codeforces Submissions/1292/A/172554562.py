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

n,q = list(map(int, input().split()))
s = [[0]*n for _ in range(2)]
cur = 0
for i in range(q):
    x,y = LI()
    x -= 1
    y -= 1
    if s[x][y]==0:
        s[x][y] = 1
        for yy in range(y-1,y+2):
            if 0<=yy<n and s[1-x][yy]==1:
                cur += 1
    else:
        s[x][y] = 0
        for yy in range(y-1,y+2):
            if 0<=yy<n and s[1-x][yy]==1:
                cur -= 1
    pans(cur==0)