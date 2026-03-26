t = int(input())

while t != 0:
    a, b = map(int, input().split())

    #a* vi theo quy tac nhan, con b luon co dang 9999999...
    #vd 1 -> 1+9+1*9 = 19, 2 = 2+9+2*9 = 29

    #str(b+1) xong lay len -1
    #vi 99 se co len(100)-1 = 2
    #98 len(99)-1 = 1 (van la 1 cach)

    print( a * ( (len( str(b+1) )) - 1 ))
    
    
    t -= 1