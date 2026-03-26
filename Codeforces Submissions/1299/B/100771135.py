import sys; import math; 
CASE=0; rla=''



def solve() : 
    n=int(rla)
    if n&1 : 
        for i in range(n) : a, b=map(int, input().split())
        print("NO"); return
    else : 
        x=[]; y=[]
        for i in range(n>>1) : 
            a, b=map(int, input().split())
            x.append(a); y.append(b)
        flag=0
        a, b=map(int, input().split())
        for i in range(1, (n>>1)) : 
            c, d=map(int, input().split())
            if c-a!=x[i-1]-x[i] or d-b!=y[i-1]-y[i] : flag=1
            a=c; b=d
        print("NO" if flag==1 else "YES")

while True : 
    rla=sys.stdin.readline()
    cases=1
    if not rla: break
    if (rla=='\n')|(rla=='') : continue
    if CASE==1 : cases=int(rla)
    for cas in range(cases) : 
        
        solve()
    

