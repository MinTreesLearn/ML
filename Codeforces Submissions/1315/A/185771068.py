from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))

def answer():

    quad1 = x * b
    quad2 = (a - x - 1) * b
    quad3 = y * a
    quad4 = (b - y - 1) * a

    ans = max(quad1 , quad2 , quad3 , quad4)
    return ans
    
    
for T in range(int(input())):

    a , b , x , y = inp()


    print(answer())
    
