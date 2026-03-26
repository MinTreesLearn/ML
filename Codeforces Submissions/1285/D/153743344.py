import sys
input=lambda:sys.stdin.readline().rstrip()
def calc(A,i,j,k):
	if k==0:
		return 0
	if A[i]%(k*2)>=k or A[j]%(k*2)<k:
		return calc(A,i,j,k//2)
	index=i+[l%(k*2)>=k for l in A[i:j+1]].index(1)
	return k+min(calc(A,i,index-1,k//2),calc(A,index,j,k//2))
def solve():
	n=int(input())
	A=sorted(list(map(int,input().split())))
	print(calc(A,0,n-1,pow(2,30)))
T=1
for i in range(T):
	solve()