import sys
input=lambda:sys.stdin.readline().rstrip()
def solve():
	n,q=map(int,input().split())
	state=[[0 for i in range(n+2)] for j in range(2)]
	count=0
	for i in range(q):
		r,c=map(int,input().split())
		state[r-1][c]=1-state[r-1][c]
		count+=sum(state[2-r][c-1:c+2])*(2*state[r-1][c]-1)
		print(['No','Yes'][count==0])
T=1
for i in range(T):
	solve()