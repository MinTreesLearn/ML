def isvalid(points,z):
    mid=[points[0][0]+points[z][0],points[0][1]+points[z][1]]
    for i in range(len(points)//2):
        curr=[points[i][0]+points[i+z][0],points[i][1]+points[i+z][1]]
        if(curr!=mid):
            return 0
    return 1
n=int(input())
points=[]
for i in range(n):
    l=input().split()
    x=int(l[0])
    y=int(l[1])
    points.append((x,y))
if(n%2):
    print("NO")
else:
    z=n//2
    if(isvalid(points,z)):
        print("YES")
    else:
        print("NO")
