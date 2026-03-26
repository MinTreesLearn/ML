from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))

def answer():

    cost = 0
    ans , cur = n , "?"
    for i in range(n - 2 , -1 , -1):
        
        if(s[i] != cur):
            cur = s[i]
            if(cur == 'A'):cost += a
            else:cost += b

        if(cost <= p):
            ans = i + 1
        else:break

    return ans
            
    
for T in range(int(input())):

    a , b , p = inp()
    s = input().strip()
    n = len(s)


    print(answer())
    
