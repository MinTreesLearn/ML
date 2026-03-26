n = int(input())
while n:
    n-=1
    l = int(input())
    num = int(input())
    new = 0
    while num>0:
        last = num%10
        if last%2!=0:
            new*=10
            new+=last
        num = num//10
        # print(num)
    new = str(new)
    new = new[::-1]
    if len(new)==1:
        print(-1)
    elif len(new)%2==0:
        print(new)
    else:
        print(new[:-1])