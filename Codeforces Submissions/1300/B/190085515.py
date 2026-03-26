n=int(input())
t=1
while(t<=n):
    no=int(input())
    arr=[int(k) for k in input().split()]
    arr.sort()
    print(arr[no]-arr[no-1])
    t+=1