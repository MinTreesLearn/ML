'https://codeforces.com/contest/1293/problem/A'
for _ in range(int(input())):
	n,s,k=map(int,input().split())
	num=list(map(int,input().split()))
	for i in range(n):
		left=s-i
		right=s+i
		if(left>=1 and left not in num):
			print(i)
			break
		if(right<=n and right not in num):
			print(i)
			break
	else: assert(False)