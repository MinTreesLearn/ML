# 13:01-
import sys
input = lambda: sys.stdin.readline().rstrip()

N,a,b,K = map(int, input().split())
A = list(map(int, input().split()))

total = a+b
ans = 0
B = []
for i in range(N):
	t = A[i]%total
	if t==0:
		t = total
	if t>a:
		B.append((t-a-1)//a+1)
	else:
		ans += 1

B.sort(reverse=True)
while K>0 and B:
	t = B.pop()
	if K>=t:
		ans+=1
	K-=t

print(ans)

