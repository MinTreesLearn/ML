#1 2 3 4 5 6 7 8
#1 2 3 4 5 6 7 8 9 10 11 12
#6
#1 2 3 4 5 7 8 9 10 11 12
#1 2 3 4 5 6
import math
for _ in range(int(input())):
    # n,m=map(int,input().split())
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    # print(a)
    print(a[n] - a[n - 1])

