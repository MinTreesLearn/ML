import sys
input = lambda: sys.stdin.readline().rstrip("\n\r")
import math

def solve():  
    a, b, c = list(map(int, input().split()))
    ans = math.inf
    lst = [0, 0, 0]    
    for i in range(1, 10001):
        for j in factors[i]:
            p = j * (c // j)
            q = j * (c // j + 1)
            k = None
            z = None
            if abs(c - p) < abs(c - q):
                k = p
                z = abs(c - p)
            else:
                k = q
                z = abs(c - q)
            y = abs(b - j)
            x = abs(a - i)
            
            if x + y + z < ans:
                
                ans = x + y + z
                lst = [i, j, k]
    print(ans)
    print(*lst)

factors = [[] for i in range(10001)]
for i in range(1, 10001):
    x = i
    ind = 1
    while True:
        val = x * ind
        if val > 20001:
            break
        factors[i].append(val)
        ind += 1
for _ in range(int(input())):
    solve()


    