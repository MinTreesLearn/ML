for a0 in range(int(input())):
    n,k = map(int,input().split())
    a,b = k,k
    t,l,r = [0 for i in range(n)],[0 for i in range(n)],[0 for i in range(n)]
    for i in range(n):
        t[i],l[i],r[i] = map(int,input().split())
    t.insert(0,0)
    for i in range(n):
        b+=t[i+1] - t[i]
        a-=t[i+1] - t[i]
        if (a > r[i]) or (b < l[i]):
            print("NO")
            break
        else:
            b = min(b,r[i])
            a = max(a,l[i])
    else:
        print("YES")