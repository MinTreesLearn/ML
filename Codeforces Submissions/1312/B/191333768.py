for i in range(int(input())):
    a=input()
    l1=[]
    l1.append([int(x) for x in input().split()])
    l2=l1[0]
    l2.sort()
    l2.reverse()
    for i in l2:
        print(i,end=" ")
    print()