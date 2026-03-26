import sys
input = sys.stdin.readline
n = int(input())
b = list(map(int,input().split()))
dum = (n//2) + 1
nxtd_arr = [[[101,101] for _ in range(dum)]for _ in range(n + 1)]

nxtd_arr[0][0][0] = nxtd_arr[0][0][1] = 0

for i in range(1, n + 1):
	if b[i - 1] == 0:
		for j in range(1, dum):
			nxtd_arr[i][j][0] = min(nxtd_arr[i - 1][j - 1][0],nxtd_arr[i - 1][j - 1][1] + 1)
		for j in range(dum):
			nxtd_arr[i][j][1] = min(nxtd_arr[i - 1][j][0] + 1,nxtd_arr[i - 1][j][1])
	else:
		if b[i - 1] % 2 == 0:
			for j in range(1, dum):
				nxtd_arr[i][j][0] = min(nxtd_arr[i - 1][j - 1][0],nxtd_arr[i - 1][j - 1][1] + 1)
		else:
			for j in range(dum):
				nxtd_arr[i][j][1] = min(nxtd_arr[i - 1][j][0] + 1,nxtd_arr[i - 1][j][1])
print(min(nxtd_arr[-1][-1]))