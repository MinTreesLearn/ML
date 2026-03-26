import heapq
from collections import defaultdict


def solve(N, A, T):
    # Find conflicting nums
    numToConflicts = defaultdict(list)
    for i, x in enumerate(A):
        numToConflicts[x].append(i)

    # Iterate the conflict nums in heap since possible nums is in 10**9
    # Pick the best to keep for each num, all other conflicts get scooted forward in another heap
    conflictNums = list(numToConflicts.keys())
    heapq.heapify(conflictNums)
    scoot = []
    assigned = 0
    cost = 0
    while assigned != N:
        num = heapq.heappop(conflictNums)

        heapCost = float("-inf")
        if scoot:
            heapCost, fromNum = scoot[0]
            heapCost *= -1

        conflictCost = float("-inf")
        indices = []
        if num in numToConflicts:
            indices = numToConflicts[num]
            maxIndex = max(indices, key=lambda i: T[i])
            conflictCost = T[maxIndex]

        # Pick costliest from conflicts or heap
        if heapCost > conflictCost:
            # Use the heap for this cell
            heapq.heappop(scoot)
            cost += (num - fromNum) * heapCost
        else:
            # Use the costliest of the existing indices for this cell
            indices = filter(lambda x: x != maxIndex, indices)
        assigned += 1

        # Scoot everything else into the heap
        for i in indices:
            heapq.heappush(scoot, (-T[i], num))
        # If there's something being scooted, make sure the next num is num + 1
        if scoot and (not conflictNums or conflictNums[0] != num + 1):
            heapq.heappush(conflictNums, num + 1)
    return cost


if __name__ == "__main__":
    N, = map(int, input().split())
    A = [int(x) for x in input().split()]
    T = [int(x) for x in input().split()]
    ans = solve(N, A, T)
    print(ans)
