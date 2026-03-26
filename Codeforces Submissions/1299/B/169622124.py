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
xy = [LI() for _ in range(n)]
xy.append(xy[0])
if n%2==0:
    for i in range(n//2):
        px,py = xy[i+1][0]-xy[i][0], xy[i+1][1] - xy[i][1]
        qx,qy = xy[n//2+i+1][0]-xy[n//2+i][0], xy[n//2+i+1][1] - xy[n//2+i][1]
#         print(px,py,qx,qy)
        if px==-qx and py==-qy:
            pass
        else:
            print("No")
            break
    else:
        print("Yes")
else:
    print("No")