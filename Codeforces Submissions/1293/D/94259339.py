x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
cand=[[x0,y0]]
while True:
    cand.append([ax*cand[-1][0]+bx,ay*cand[-1][1]+by])
    if abs(ax*cand[-1][0]+bx-xs)+abs(ay*cand[-1][1]+by-ys)>10**30:
        break
inf=10**30
l=len(cand)
def check(j):
    ret=0
    s=t
    i=j
    s-=abs(xs-cand[i][0])+abs(ys-cand[i][1])
    if s<0:
        return ret
    ret+=1
    while i!=0:
        i-=1
        s-=((cand[i+1][0]-cand[i][0])+(cand[i+1][1]-cand[i][1]))
        if s<0:
            return ret
        ret+=1
    i=j+1
    s-=((cand[i][0]-cand[0][0])+(cand[i][1]-cand[0][1]))
    #print(4,j,ret,s)
    if s<0:
        return ret
    ret+=1
    while True:
        s-=((cand[i+1][0]-cand[i][0])+(cand[i+1][1]-cand[i][1]))
        if s<0:
            return ret
        i+=1
        ret+=1
#print([check(i) for i in range(l)])   
print(max([check(i) for i in range(l)]))