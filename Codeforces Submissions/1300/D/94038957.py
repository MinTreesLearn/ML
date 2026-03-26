n=int(input())
points=[]
for i in range(n):
    points.append(list(map(int,input().split())))
if n%2==1:
    print("No")
    exit()
edges=[]
for i in range(n-1):
    edges.append([points[i+1][0]-points[i][0],points[i+1][1]-points[i][1]])
edges.append([points[0][0]-points[n-1][0],points[0][1]-points[n-1][1]])
#print(edges)
for i in range(n//2):
    if edges[i][0]+edges[i+n//2][0]!=0 or edges[i][1]+edges[i+n//2][1]!=0:
        #print(i)
        #print(points[i][0]+points[i+n//2][0])
        #print(points[i][1]+points[i+n//2][1])
        print("No")
        exit()
print("Yes")