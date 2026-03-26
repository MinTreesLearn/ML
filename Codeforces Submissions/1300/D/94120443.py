import os,io
import sys
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n=int(input())
shape=[]
for _ in range(n):
    x,y=map(int,input().split())
    shape.append([x,y])
if n%2==1:
    print('NO')
    sys.exit()
for i in range(n):
    if shape[i][0]-shape[i-1][0]!=shape[(n//2+i-1)%n][0]-shape[(n//2+i)%n][0]:
        print('NO')
        sys.exit()
    if shape[i][1]-shape[i-1][1]!=shape[(n//2+i-1)%n][1]-shape[(n//2+i)%n][1]:
        print('NO')
        sys.exit()
print('YES')