N,Q = map(int,input().split())
dat = [[0]*N for _ in range(2)]
num = 0
def check(x,y):
	l = 0
	for i in range(-1,2):
		if 0<=i+x<N and dat[abs(y-1)][i+x]==1:
			l += 1
	return l

num = 0
for i in range(Q):
	y,x = map(int,input().split())
	l = check(x-1,y-1)
	if dat[y-1][x-1]==0:
		if l!=0:
			num += l
	else:
		num -= l
	dat[y-1][x-1] = abs(dat[y-1][x-1]-1)
	if num==0:
		print("Yes")
	else:
		print("No")


