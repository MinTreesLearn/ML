t = int(input())
for Cases in range(t):

    n = int(input()); a = list(map(int,input().split()))
    dp = [0]*(n); dp[0] = a[0]; rem = [0]*n
    
    for i in range(1,n):
        dp[i] = max(dp[i-1]+a[i],a[i])
        if dp[i] == a[i]: rem[i] = i
        elif dp[i] == dp[i-1]+a[i]: rem[i] = rem[i-1]
    
    if sum(a) > max(dp): print("YES")
    elif sum(a) == max(dp) and dp.count(sum(a)) == 1\
        and sum(a) == dp[-1] and rem[-1] == 0: print("YES")
    else: print("NO")