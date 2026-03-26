n, m = map(int, input().split())

numList = [x+1 for x in range(n)]
backdoor = []

count = sum([(i-1) // 2 for i in range(1, n+1)])

if count < m: exit(print(-1))

while count > m:
	lastpop = numList.pop()
	count -= (lastpop - 1) // 2

	if count >= m:
		if len(backdoor) == 0: backdoor.append(10 ** 9)
		else: backdoor.append(backdoor[-1] - 2 ** 16)
	else:
		gap = m - count
		backdoor.append(2 * (lastpop - gap) - 1)
		count += gap

while len(backdoor) > 0: numList.append(backdoor.pop())

print(' '.join([str(x) for x in numList]))