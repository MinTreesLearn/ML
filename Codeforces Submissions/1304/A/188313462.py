for i in [*open(0)][1:]:
    x,y,a,b=map(int,i.split())
    a+=b
    y-=x
    print([y//a,-1][y%a>0])  