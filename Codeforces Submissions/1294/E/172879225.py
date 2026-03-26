from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

"""
we can just solve it column independent
"""

def answer():

    ans = 0
    for j in range(m):

        take = [0 for i in range(n)]
        for i in range(n):

            x = (a[i][j] - j - 1)

            if(x >= 0 and x % m == 0):

                v = (x // m)
                if(v >= n):continue
                
                if(v <= i):take[i - v] += 1
                else:take[i + n - v] += 1

        best = float('inf')
        for i in range(n):
            best = min(best , i + (n - take[i]))

        ans += best

    return ans
    

for T in range(1):

    n , m = inp()
    a = [inp() for i in range(n)]
    

    print(answer())
