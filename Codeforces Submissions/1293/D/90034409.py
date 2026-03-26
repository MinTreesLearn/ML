x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

nodes = [(x0, y0)]

while nodes[-1][0] <= max(t, xs) and nodes[-1][1] <= max(t, ys):
	nodes.append((ax * nodes[-1][0] + bx, ay * nodes[-1][1] + by))

ans = 0

for i in range(len(nodes)):
	for j in range(i, len(nodes)):
		dist = abs(nodes[j][0] - nodes[i][0]) + \
				abs(nodes[j][1] - nodes[i][1])
		fromleft = abs(nodes[i][0] - xs) + abs(nodes[i][1] - ys)
		fromright = abs(nodes[j][0] - xs) + abs(nodes[j][1] - ys)
		if dist + fromleft <= t or dist + fromright <= t:
			ans = max(ans, j - i + 1)

print(ans)