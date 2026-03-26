num=int(input())
for i in range(num):
    n,m=[int(i) for i in input().split()]
    c=0
    f=m-n
    if f==0:
        print("0")
    for j in range(1):
        if f>0:
            if f%2!=0:
                print("1")
            else:
                print("2")
        elif f<0:
            if f%2==0:
                print("1")
            elif f%2!=0:
                print("2")