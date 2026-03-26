for i in range(int(input())):
    Number=int(input())
    listNum=list(map(int,input().split()))
    count=sum(listNum)
    odd=0
    even=0
    for j in range(Number):
        if(listNum[j]%2==1):
            odd+=listNum[j]
        else:
            even+=listNum[j]
    if(count%2==1):
        print('YES')
    else:
        if(odd!=0 and even!=0):
            print('YES')
        else:
            print('NO')
