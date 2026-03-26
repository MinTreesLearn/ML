for i in' '*int(input()):
    x,y,a,b=map(int,input().split())
    print([(y-x)//(a + b),-1][(y-x)%(a+b)>0])        
