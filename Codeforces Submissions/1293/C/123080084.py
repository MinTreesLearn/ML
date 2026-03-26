from sys import stdin
input=stdin.readline
def maze(arr,n):
	ans=[[0,0] for i in range(n)]
	flow=[]
	bad=[[0,0] for i in range(n)]
	lf=0
	badc=0
	for x,y in arr:
		if ans[y][x]==0:
			ans[y][x]=1
			f=False
			if y+1<len(ans):
				if ans[y+1][x^1]==1:
					bad[y + 1][ x ^ 1]+=1
					bad[y][ x]+=1
					badc+=2
			if y-1>=0:
				if ans[y-1][x^1]==1:
					bad[y-1][ x ^1]+=1
					bad[y][ x]+=1
					badc+=2
			if ans[y][x^1]==1:
				bad[y ][ x ^ 1]+=1
				bad[y][ x]+=1
				badc+=2
		elif  ans[y][x]==1:
			ans[y][x]=0
			pt=0
			if bad[y][x]:
				dx=x^1
				for dy in [-1,0,1]:
					if y+dy<n and y+dy>=0:
						if bad[y+dy][dx]:
							bad[y][x]-=1
							bad[y+dy][dx]-=1
							badc-=2
		# print(bad)
		if badc!=0:
			print("NO")
		else:
			print("YES")
	return ""


a,b=map(int,input().strip().split())
blanck=[]
for i in range(b):
	x,y=map(int,input().strip().split())
	blanck.append([x-1,y-1])
print(maze(blanck,a))

'''
10 8
2 6
1 5
2 6
2 4
2 4
1 6
2 5
2 5
'''