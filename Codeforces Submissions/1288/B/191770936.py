for _ in range(int(input())) : 
    a,b = map(int,input().split())
    i = 0 
    x = 9
    while x <= b : x*=10; x += 9; i += 1
    print(a*i)