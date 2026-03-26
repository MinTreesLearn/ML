import sys
input=lambda:sys.stdin.readline().rstrip()
N=int(input())
A=list(map(int,input().split()))
if max(A)==0:
	print(1 if N>1 else 0)
	sys.exit()
B,L=[],[0]
rem=[N//2,(N+1)//2]
ans=2
dp,dp2=[[],[]],[[],[]]
for i in A:
	if i>0:
		L.append(0)
		B.append(i)
		rem[i%2]-=1
	else:
		L[-1]+=1
for i in range(1,len(L)-1):
	if B[i-1]%2!=B[i]%2:
		ans+=1
	else:
		dp[B[i]%2].append(L[i])
		ans+=2
dp2[B[0]%2].append(L[0])
dp2[B[len(B)-1]%2].append(L[len(L)-1])
for i in range(2):
	dp[i]=sorted(dp[i])
	for j in range(len(dp[i])):
		if rem[i]>=dp[i][j]:
			rem[i]-=dp[i][j]
			ans-=2
	for j in range(len(dp2[i])):
		if rem[i]>=dp2[i][j]:
			rem[i]-=dp2[i][j]
			ans-=1
print(ans)
		