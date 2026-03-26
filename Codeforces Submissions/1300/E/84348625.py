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
    # Also TLE, not sure about correctness
    pref = [0]
    for x in A:
        pref.append(pref[-1] + x)
    i = 0
    while i < N:
        best = (A[i], i, i + 1)
        for j in range(i + 1, N + 1):
            avg = (pref[j] - pref[i]) / (j - i)
            best = min(best, (avg, i, j))
        if best[0] < A[i]:
            avg, i, j = best
            A[i:j] = [avg] * (j - i)
            i = j
        else:
            i += 1
    return "\n".join(map(str, A))


def solve(N, A):
    # Answer is always monotonically increasing (suppose not, then you can average the decrease to get something lexicographically smaller)

    # Track the monotonically increasing heights and number of consecutive columns with that that height

    # TODO: This TLEs but shouldn't this be amortized linear? Total number of appends is N. Total number of pops are limited by appends.

    heights = [(0, 0)]

    def combine(hw1, hw2):
        h1, w1 = hw1
        h2, w2 = hw2
        total = h1 * w1 + h2 * w2
        w = w1 + w2
        return (total / w, w)

    cost = 0
    for x in A:
        hw = (x, 1)
        while True:
            c = combine(heights[-1], hw)
            if c[0] <= heights[-1][0]:
                heights.pop()
                hw = c
            else:
                heights.append(hw)
                cost += 1
                break
    assert cost == N

    ans = []
    for h, w in heights:
        ans.extend([str(h)] * w)
    return "\n".join(ans)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    (N,) = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    ans = solve(N, A)
    print(ans)
