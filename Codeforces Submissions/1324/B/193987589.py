t = int(input())
while t>0:
    n = int(input())
    arr = list(map(int,input().split()))
    f = 0
    arr1 = []
    for i in range(n):
        arr1.append((arr[i],i))
    arr1 = sorted(arr1)
    for i in range(n-1):
        if (arr1[i][0] == arr1[i+1][0]) and (arr1[i+1][1]-arr1[i][1])>1:
            f = 1
            break
        if i<n-2:
            if (arr1[i][0] == arr1[i+1][0]) and (arr1[i+1][0]==arr1[i+2][0]):
                f = 1
                break

    if f>0:
        print('YES')
    else:
        print('NO')
    t = t-1