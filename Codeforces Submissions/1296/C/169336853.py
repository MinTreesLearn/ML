import sys;sc = sys.stdin.readline;out=sys.stdout.write
for _ in range(int(sc())):
    n=int(sc());s=str(input());p=[0,0];d={(0,0):1};r,l,ind=n,0,1
    for e in range(n):
        if s[e]=='L':p[0]-=1
        elif s[e]=='R':p[0]+=1
        elif s[e]=='U':p[1]+=1
        else:p[1]-=1
        p=tuple(p)
        if p in d and r-l>ind-d[p]:l,r=d[p],ind
        ind+=1;d[p]=ind;p=list(p)
    if l: out(str(l)+str(" ")+str(r)+"\n")
    else: out("-1\n")