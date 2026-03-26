def md(xi,yi,xs,ys): return abs(xs-xi)+abs(ys-yi)

def case1(D,S,t):
    i = D.index(min(D))
    for j in range(i,-1,-1):
        if D[i]+S[i]-S[j]>t:
            return i-j
    return i+1

def case2(D,S,t):
    for i in range(len(S)):
        if D[i]+S[i]>t:
            return i
    return len(S)

def case3(D,S,t):
    for i in range(len(S)):
        if D[0]+S[i]>t:
            return i
    return len(S)

x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
D = []#s to i
S = []#0 to i
x,y = x0,y0
while not S or S[-1]<=t or x<=xs or y<=ys:
    S.append(md(x,y,x0,y0))
    D.append(md(x,y,xs,ys))
    x *= ax
    x += bx
    y *= ay
    y += by
print(max(case1(D,S,t),case2(D,S,t),case3(D,S,t)))

