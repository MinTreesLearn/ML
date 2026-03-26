t=int(input())
for i in range(t):
    arr=list(map(int,input().split()))
    total=sum(arr)
    maximum=max(arr[0:3])
    if(total%3==0 and total/3 >= maximum):
        print("YES")
    else:
        print("NO")
