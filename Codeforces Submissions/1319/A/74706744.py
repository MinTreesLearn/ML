import math
n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
if a==b:
    print(-1)
else:
    count=0
    count1=0
    for i in range(n):
        if a[i]>b[i]:
            count+=1
        elif b[i]>a[i]:
            count1+=1
    if count!=0:
        print(math.ceil((count1+1)/count))
    else:
        print(-1)