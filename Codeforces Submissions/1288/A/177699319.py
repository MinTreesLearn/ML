def time(x, d):
    return(x+d/(x+1))
t = int(input())
for xx in range(t):
    n, d = map(int,input().split())
    l = 0
    r = d - 1
    ans = "NO"
    if d <= n:
        ans = "YES"
    else:
        while l < r:
            m1 = (l+((r-l)//3))
            m2 = (l+((2*(r-l))//3))
            tm1 = time(m1, d)
            tm2 = time(m2, d)
#            print(m1, tm1, m2, tm2, " ", l, r)
            if tm1 <= n or tm2 <= n:
                ans = "YES"
                break
            if tm1 == tm2:
                l = m1
                r = m2
            elif tm1 > tm2:
                l = m1 + 1
            else:
                r = m2 - 1
    print(ans)