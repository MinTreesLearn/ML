#Abir Kundu  31.01.2023 h
t=int (input ())
while t>0:
    t-=1
    n=int (input ())
    if n%2==0:
        print ("1"*(n//2)) # this 1s numbers will be maximum 
    else: #for odd
        print ("7"+"1"*((n-3)//2)) 
        # 7 needs 3 segments , we have n-3 segments 
        # odd -odd == even
        # only for even segments 1s numbers will be maximum 
        
        # n//2 because 1 takes 2 segments to print 