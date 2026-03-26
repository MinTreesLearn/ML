import sys
input=lambda:sys.stdin.readline().rstrip()
def trans(a,v):
	ret=0
	for i in range(len(a)):
		ret*=2
		ret+=a[i]>=v
	return ret
def solve():
	n,m=map(int,input().split())
	a=[list(map(int,input().split())) for i in range(n)]
	bis=[-1,pow(10,9)+1]
	ans=[]
	while bis[1]-bis[0]>1:
		flg=1
		mid=sum(bis)//2
		dp={}
		for i in range(n):
			res=trans(a[i],mid)
			if not res in dp:
				dp[res]=i
				for j in dp:
					if j|res==pow(2,m)-1:
						ans=[dp[j]+1,dp[res]+1]
						flg=0
		bis[flg]=mid
	print(*ans)
T=1
for i in range(T):
	solve()