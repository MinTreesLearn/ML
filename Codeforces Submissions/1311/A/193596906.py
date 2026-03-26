for i in range(int(input())):
    a,b=map(int,input().split())
    if(a==b):
        print(0)
    elif(a%2==0 and b%2==0):
        if(a>b):
            print(1)
        else:
            print(2)
    elif(a%2==1 and b%2==1):
        if (a > b):
            print(1)
        else:
            print(2)
    else:
        if(a>b):
            print(2)
        else:
            print(1)

