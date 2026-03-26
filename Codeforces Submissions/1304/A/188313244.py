for i in [*open(0)][1:]:
    x,y,a,b=map(int,i.split())
    print([(y-x)//(a + b),-1][(y-x)%(a+b)>0])