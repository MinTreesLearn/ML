def check(x):
    l, r = 0, k
    while l < r:
        m = l + (r - l) // 2
        if arr[m] == x:
            return m 
        elif arr[m] > x:
            r = m
        else:
            l = m + 1
    
    return -1

for _ in range(int(input())):
    n, s, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    cnt = 0
    d, u = s - cnt, s + cnt 
    while d >= 0 and u <= n:
        if check(d) == -1 or check(u) == -1:
            print(cnt)
            break
        else:
            cnt += 1 
            if d > 1:
                d = s - cnt 
            if u < n:
                u = s + cnt

        # print(d, u)
        

    
    