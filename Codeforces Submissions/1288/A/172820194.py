from math import ceil 
for _ in range(int(input())):
    n, d = [int(i) for i in input().split()] 
    if ceil(d/(n//2+1))+n//2 <= n : print("YES") 
    else : print("NO")