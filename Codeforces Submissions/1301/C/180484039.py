from sys import stdin
input = stdin.readline
import math 

for case in range(int(input())):
    n, m = map(int, input().split())
    ans = n * (n + 1) // 2
    
    small = (n - m)//(m + 1); avg_split = (n - m)/(m + 1)
    large = small + 1

    
    num_large = (n - m) % (m + 1)
    num_small = m + 1 - num_large

    ans -= (num_large * large * (large + 1)// 2 + num_small * small * (small + 1)//2)
    
    print(int(ans))




    



