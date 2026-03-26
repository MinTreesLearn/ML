import sys

for i in range(int(sys.stdin.readline())):
    s = int(sys.stdin.readline())
    ls = [int(a) for a in sys.stdin.readline().split()]
    
    par = 1
    
    if ls[0] % 2 == 0:
        par = 0
    
    
    f = True
    
    for i in ls:
        if i % 2 != par:
            f = False
            break
    
    if f:
        print("YES")
        continue
    print("NO")