n=int(input())
f=[[[1000,1000]for _ in range(n+1)]for _ in range(n+1)]
f[0][0]=[0,0]
for i,v in enumerate(map(int,input().split())):
	for j in range(i+2):
		if v==0 or v%2:f[i+1][j][1]=min(f[i][j][0]+1,f[i][j][1])
		if v%2==0:f[i+1][j][0]=min(f[i][j-1][0],f[i][j-1][1]+1)
print(min(f[n][n//2]))