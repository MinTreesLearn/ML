from sys import stdin
input = stdin.readline

def answer():

    maxrank = min(n , x + y - 1)


    if((x + y) <= n):
        minrank = 1
    else:

        m = min(x , y)

        if(m != n):minrank = (x + y + 1) - n
        else:minrank = n


    return [minrank , maxrank]
    

   
for T in range(int(input())):

    n , x , y = map(int,input().split())

    print(*answer())

    
