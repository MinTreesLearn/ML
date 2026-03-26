for q in range(int(input())):
    n,d = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    ans = arr[0]
    for i in range(1,n):
        temp = min(arr[i], d//i)
        ans += temp
        d -= temp*(i)
    print(ans)    
