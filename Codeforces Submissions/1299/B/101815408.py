import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)

def isParallel(p1a,p1b,p2a,p2b):
    dx1=p1a[0]-p1b[0]
    dy1=p1a[1]-p1b[1]
    
    dx2=p2a[0]-p2b[0]
    dy2=p2a[1]-p2b[1]
    
    return dx1==dx2 and dy1==dy2

n=int(input())
xy=[] #[[x,y]]
for _ in range(n):
    a,b=[int(z) for z in input().split()]
    xy.append([a,b])

#YES if each line is parallel to another line
#xy.sort(key=lambda z:(z[0],z[1])) #no need to sort since polygon given in ccw direction
#xy[0] will match with xy[n-1],xy[1] will match with xy[n-2] etc.
if n%2==1:
    print('NO')
else:
    ans='YES'
    for i in range(n//2):
        p1a=xy[i]
        p1b=xy[i+1]
        j=i+n//2
        p2a=xy[(j+1)%n]
        p2b=xy[(j)]
        if not isParallel(p1a,p1b,p2a,p2b):
            ans='NO'
            break
    print(ans)