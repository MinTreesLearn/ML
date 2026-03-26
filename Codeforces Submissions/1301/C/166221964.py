import sys 
input = sys.stdin.readline 

t = int(input())
while(t):
    n, m = map(int, input().split())
    z = n - m 
    g = m + 1 
    k = z // g 
    print(n * (n + 1) // 2 - k * (k + 1) // 2 * g - (k + 1) * (z % g)) 
    
    t -= 1