n,m = tuple(map(int,input().split()))

steps = 0
if n == m :
    print(steps)
elif m%n != 0:
    print(-1)
else:
    d = m/n    
    while d % 2 == 0:
        d /= 2
        steps += 1
    while d % 3 == 0:
        d /= 3
        steps += 1
    if d != 1:
        steps = -1
        
    print(steps)

