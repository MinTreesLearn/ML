def solve(n, l):
    c = 0
    for i in range(1, n):
        c = max(c, abs(l[i] - l[i - 1]))
    return c

t = int(input())
while(t):
    n = int(input())
    l = list(map(int, input().split()))
    a = []
    
    for i in range(n - 1):
        if(l[i] != -1 and l[i + 1] == -1):
            a.append(l[i])
        elif(l[i + 1] != -1 and l[i] == -1):
            a.append(l[i + 1])
    if(not a):
        print(0, 0) 
    else:
        k = (max(a) + min(a) + 1) // 2 
        l = [k if i == -1 else i for i in l]
        m = solve(n, l)
        print(m, k)
   
    t -= 1