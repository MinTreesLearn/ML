def main():
	from collections import defaultdict
	import sys
	input = sys.stdin.buffer.readline

	n = int(input())
	a = list(map(int, input().split()))
	t = list(map(int, input().split()))
	d = defaultdict(list)
	for i in range(n): d[a[i]].append(t[i])
	a.sort()
	Q = []
	from heapq import heapify, heappop, heappush
	heapify(Q)
	cur_sum = 0
	ans = 0
	l = sorted(list(d.keys()))
	for i in range(len(l)):
		c = l[i]
		for v in d[l[i]]:
			cur_sum += v
			heappush(Q, -v)
		while Q and (i == len(l) - 1 or (i < len(l) - 1 and c < l[i + 1])):
			p = heappop(Q)
			cur_sum += p
			ans += cur_sum
			c += 1
	print(ans)
if __name__ == '__main__':
	main()
	