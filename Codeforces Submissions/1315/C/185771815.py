from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))

def answer():

    cantake = set([i for i in range(1 , 2 * n + 1)])
    
    ans = [-1 for i in range(2 * n)]
    for i in range(n):
        ans[2 * i] = a[i]
        cantake.remove(a[i])
        

    for i in range(n):

        ok = False
        for j in range(a[i] , 2 * n + 1):
            if(j in cantake):
                ans[2 * i + 1] = j
                cantake.remove(j)
                ok = True
                break

        if(not ok):return [-1]

    return ans
    
for T in range(int(input())):

    n = int(input())
    a = inp()


    print(*answer())
    
