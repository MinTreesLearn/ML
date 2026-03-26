for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split(' ')))
    if n == 1:
        print('Yes')
        continue
    left, right = [], []
    cntL, cntR = 0, 0
    for i in range(n):
        if arr[i] >= i:
            cntL += 1
        if arr[n-1-i] >= i:
            cntR += 1
        left.append(cntL)
        right.append(cntR)
    right = right[::-1]
    k = 0
    ans = 'No'
    while k < n-1:
        if left[k] + right[k+1] == n:
            if arr[k] != arr[k+1]:
                ans = 'Yes'
                break
            elif arr[k]-1 > k or arr[k+1] > n-k-2:
                ans = 'Yes'
                break 
            
        k += 1
    print(ans)