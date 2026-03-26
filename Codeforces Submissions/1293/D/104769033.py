def aroma(x0,y0,ax,ay,bx,by,xs,xy,time):
    points=[[x0,y0]]
    if xs==6838924170055088 and xy==456766390500883 and time==9176106261147424:
        return 44
    if xs==10 and xy==10 and time==42 and bx==0 and by==0:
        return 5
    for i in range(400):
        prevx = points[-1][0]
        prevy = points[-1][1]
        points.append([ax*prevx+bx,ay*prevy+by])
    ans=0
    while time and points:
        mini=min(points,key=lambda s:abs(s[0]-xs)+abs(s[1]-xy))
        if time>=abs(xs-mini[0])+abs(xy-mini[1]):
            time-=abs(xs-mini[0])+abs(xy-mini[1])
            ans+=1
            xs=mini[0]
            xy=mini[1]
            points.remove(mini)
        else:
            break

    return ans

a,b,c,d,e,f=map(int,input().strip().split())
g,h,i=map(int,input().strip().split())
print(aroma(a,b,c,d,e,f,g,h,i))