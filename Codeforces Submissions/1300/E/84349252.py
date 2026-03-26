import io
import os

from collections import Counter, defaultdict, deque


def solve(N, A):
    # Bruteforce just to see if logic is right. Will TLE
    for i in range(N):
        best = (A[i], i, i + 1)
        for j in range(i + 1, N + 1):
            avg = sum(A[i:j]) / (j - i)
            best = min(best, (avg, i, j))
        if best[0] < A[i]:
            avg, i, j = best
            A[i:j] = [avg] * (j - i)
    return "\n".join(map(str, A))


def solve(N, A):
    # Answer is always monotonically increasing (suppose not, then you can average the decrease to get something lexicographically smaller)

    # Track the monotonically increasing heights and number of consecutive columns with that that height
    # For each new value seen, merge with a block with same height maintaining monotonic property

    # Amortized linear. Total number of appends is N. Total number of pops is limited by appends.

    blocks = [(0, 0)]

    def combine(block1, block2):
        h1, w1 = block1
        h2, w2 = block2
        total = h1 * w1 + h2 * w2
        w = w1 + w2
        return (total / w, w)

    for x in A:
        block = (x, 1)
        while True:
            combinedBlock = combine(blocks[-1], block)
            if combinedBlock[0] <= blocks[-1][0]:
                blocks.pop()
                block = combinedBlock
            else:
                blocks.append(block)
                break

    # It seems like if you try to do map(str, ...) on a list of 10^6 floats it will TLE
    ans = []
    for h, w in blocks:
        val = str(h)
        ans.extend([val] * w)
    return "\n".join(ans)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    (N,) = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    ans = solve(N, A)
    print(ans)
