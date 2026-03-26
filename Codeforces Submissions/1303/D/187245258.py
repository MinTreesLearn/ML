def read():
	return [int(i) for i in input().split()]

def solve():
	[n,m]=read()
	a=read()
	a.sort()
	nax=64
	def cb(num,bit):
		return (num>>bit)&1
	if sum(a)<n:
		print(-1)
		return

	ct=[0 for i in range(nax)]
	for i in range(m):
		for bit in range(nax):
			if cb(a[i],bit):
				ct[bit]+=1

	ans = 0
	for bit in range(nax-1):
		if cb(n, bit) and ct[bit]==0:
			j = bit
			while ct[j]==0:
				j+=1
			ans += j-bit
			ct[j]-=1
			for k in range(bit+1,j):
				ct[k]+=1
			continue
		if cb(n, bit):
			ct[bit]-=1
		ct[bit+1]+=ct[bit]//2

	print(ans)

def main():
	for i in range(int(input())):
		solve()

main()