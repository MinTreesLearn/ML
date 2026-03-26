x = [0 for i in range(75)]
y = [0 for i in range(75)]
count1=0
count2=0
max1 = 0
def dis(x1,y1,x2,y2) :
    return abs(x1-x2)+abs(y1-y2)
def main() :
    global count1
    global max1
    global count2
    x0,y0,ax,ay,bx,by = input().split()
    x0=int(x0)
    y0=int(y0)
    ax=int(ax)
    ay=int(ay)
    bx=int(bx)
    by=int(by)
    xs,ys,t = input().split()
    xs=int(xs)
    ys=int(ys)
    t=int(t)
    x[0]=x0
    y[0]=y0
    for i in range(1,75) :
        x[i] = ax*x[i-1]+bx
        y[i] = ay*y[i-1]+by
    for i in range(0,75) :
        t1=t
        if dis(xs,ys,x[i],y[i]) <= t1 :
            t1-=dis(xs,ys,x[i],y[i])
            count1 = count1 + 1
            count2 = i
            for j in range(0,i) :
                if dis(x[i],y[i],x[j],y[j]) <=t1 :
                    t1-=dis(x[i],y[i],x[j],y[j])
                    count1=count1+i-j
                    count2=j
                    break

            for j in range(i+1,75) :
                if j==i+1 :
                    if dis(x[j],y[j],x[count2],y[count2]) <=t1 :
                        t1-=dis(x[j],y[j],x[count2],y[count2])
                        count1=count1+1
                    else :
                        max1 = max(max1,count1)
                        count1=0
                        break
                else :
                    if dis(x[j-1],y[j-1],x[j],y[j]) <= t1 :
                        t1-=dis(x[j-1],y[j-1],x[j],y[j])
                        count1=count1+1
                    else :
                        max1 =max(max1,count1)
                        count1=0
                        break
    print(max1)
main()
