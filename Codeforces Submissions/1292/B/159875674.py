import sys
input=lambda:sys.stdin.readline().rstrip()
def dist(a,b):
    return sum([abs(a[i]-b[i]) for i in range(2)])
temp=list(map(int,input().split()))
points=[temp[0:2]]
a=temp[2:4]
b=temp[4:6]
start=[0,0]
*start,t=map(int,input().split())
while points[-1][0]-start[0]<=t:
	points.append([points[-1][i]*a[i]+b[i] for i in range(2)])
for i in range(len(points)-1,-1,-1):
	for j in range(len(points)-i):
		if dist(points[j],points[j+i])+min(dist(start,points[j]),dist(start,points[j+i]))<=t:
			print(i+1)
			sys.exit()
print(0)