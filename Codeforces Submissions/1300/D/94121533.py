import sys
input=lambda:sys.stdin.readline().rstrip()

n=int(input())
if n%2:
  print("NO")
  exit()
xy=[]
xs=ys=0
for i in range(n):
  xx,yy=map(int,input().split())
  xy.append((xx,yy))
  xs+=xx
  ys+=yy
xs/=n
ys/=n
se=set(xy)
for x,y in xy:
  if not (x+(xs-x)*2,y+(ys-y)*2) in se:
    print("NO")
    exit()
print("YES")