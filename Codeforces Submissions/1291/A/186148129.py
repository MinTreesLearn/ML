for _ in range(int(input())):
    t=int(input())
    p=input()
    l=list(p)
    a=''
    for i in p:
        if int(i)%2!=0:
            a+=i
    if len(a)<2:
        print("-1")
    else:
        print(a[:2])
            