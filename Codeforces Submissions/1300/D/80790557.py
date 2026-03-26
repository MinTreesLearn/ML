import sys
input = sys.stdin.readline
from collections import *

n = int(input())
xy = [tuple(map(int, input().split())) for _ in range(n)]

if n%2==1:
    print('NO')
    exit()

mx = xy[0][0]+xy[n//2][0]
my = xy[0][1]+xy[n//2][1]

for i in range(n//2):
    xi, xj = xy[i][0], xy[i+n//2][0]
    yi, yj = xy[i][1], xy[i+n//2][1]
    
    if xi+xj!=mx or yi+yj!=my:
        print('NO')
        exit()

print('YES')