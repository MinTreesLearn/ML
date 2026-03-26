import sys
from collections import defaultdict
from heapq import heapify, heappush, heappop

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
t = list(map(int, sys.stdin.readline().split()))

# create a map that stores list of time for each value of a
umap = defaultdict(list)
for i in range(n):
    umap[a[i]].append(t[i])

# maintain a priority queue that will store time of repeating values
# this will help us in retriving/deleting greatest time
pq = []  # max heap
heapify(pq)
heapsum = 0  # to store sum of heap

ans = 0
for num in sorted(set(a)):
    if len(umap[num]) > 1 or len(pq) > 0:  # either num repeats or pq is not empty
        for val in umap[num]:
            heappush(pq, -1*val)  # store negative value since it's min heap
            heapsum += val

        # remove the largest time value
        heapsum += pq[0]
        heappop(pq)

        # increment all the other values
        temp = num
        while len(pq) > 0:
            temp += 1
            ans += heapsum
            if len(umap[temp]) > 0:
                # the next num also contains many time value
                # hence should be added in next iteration
                break
            else:
                # remove the largest time value
                heapsum += pq[0]
                heappop(pq)


print(ans)
