import sys;sc = sys.stdin.readline;out=sys.stdout.write
n, a, b, k = map(int, sc().split());ans=0
s = sorted([((int(q) % (a+b) or a+b) + a - 1) // a - 1 for q in sc().split()])
for e in s:
    if k>=e:
        k-=e;ans+=1
out(str(ans)) 