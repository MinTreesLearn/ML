def mh(p1, p2): return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

class Aroma(object):
    def __init__(self, start, max_dist):
        self.cur_ = start
        self.max_dist_ = max_dist
        self.dist_traveled_ = 0
        self.seen_ = 0

    def TryVisit(self, p):
        to_travel = mh(self.cur_, p)
        if self.dist_traveled_ + to_travel > self.max_dist_:
            return False

        self.cur_ = p
        self.dist_traveled_ += to_travel
        self.seen_ += 1

inp = [int(x) for x in input().strip().split()]
nodes = [(inp[0], inp[1])]
A = (inp[2], inp[3])
B = (inp[4], inp[5])
inp = [int(x) for x in input().strip().split()]
start = (inp[0], inp[1])
T = inp[2]

while True:
    nodes.append((A[0] * nodes[-1][0] + B[0], A[1] * nodes[-1][1] + B[1]))
    if nodes[-1][0] > 10**18 or nodes[-1][1] > 10**18:
        nodes.pop()
        break

best = 0
for i in range(len(nodes)):
    for j in range(i + 1):
        aroma = Aroma(start, T)
        for k in range(i, -1, -1):
            aroma.TryVisit(nodes[k])
        for k in range(i + 1, len(nodes)):
            aroma.TryVisit(nodes[k])

        best = max(best, aroma.seen_)

print(best)
