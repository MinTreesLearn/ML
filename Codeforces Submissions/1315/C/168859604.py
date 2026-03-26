for _ in range(int(input())):
    n = int(input()) 
    b = [int(i) for i in input().split()] 
    a = [-1] * (2*n) 
    for i in range(n): 
        a[2*i] = b[i]
        t = b[i] 
        while t in b or t in a : t+=1 
        if t > 2*n : a = [-1]; break 
        a[2*i+1] = t 
    print(*a)