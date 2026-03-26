import io
import os

from collections import deque, defaultdict, Counter

from bisect import bisect_left, bisect_right


DEBUG = False


def solveBrute(N, A):
    ans = 0
    for i in range(N):
        for j in range(i + 1, N):
            ans ^= A[i] + A[j]
    return ans


def solve(N, A):
    B = max(A).bit_length()
    ans = 0
    for k in range(B + 1):
        # Count number of pairs with kth bit on (0 indexed)
        # For example if k==2, want pairs where lower 3 bits are between 100 and 111 inclusive
        # If we mask A to the lower 3 bits, we can find all pairs that sum to either 100 to 111 or overflowed to 1100 to 1111

        MOD = 1 << (k + 1)
        MASK = MOD - 1

        # Sort by x & MASK incrementally
        left = []
        right = []
        for x in A:
            if (x >> k) & 1:
                right.append(x)
            else:
                left.append(x)
        A = left + right
        arr = [x & MASK for x in A]
        if DEBUG:
            assert arr == sorted(arr)

        numPairs = 0
        tLo = 1 << k
        tHi = (1 << (k + 1)) - 1

        for targetLo, targetHi in [(tLo, tHi), (MOD + tLo, MOD + tHi)]:
            # Want to binary search for y such that targetLo <= x + y <= targetHi
            # But this TLE so walk the lo/hi pointers instead
            lo = N
            hi = N
            for i, x in enumerate(arr):
                lo = max(lo, i + 1)
                hi = max(hi, lo)
                while lo - 1 >= i + 1 and arr[lo - 1] >= targetLo - x:
                    lo -= 1
                while hi - 1 >= lo and arr[hi - 1] > targetHi - x:
                    hi -= 1
                numPairs += hi - lo

                if DEBUG:
                    # Check
                    assert lo == bisect_left(arr, targetLo - x, i + 1)
                    assert hi == bisect_right(arr, targetHi - x, lo)
                    for j, y in enumerate(arr):
                        cond = i < j and targetLo <= x + y <= targetHi
                        if lo <= j < hi:
                            assert cond
                        else:
                            assert not cond

        ans += (numPairs % 2) << k

    return ans


if DEBUG:
    import random

    random.seed(0)
    for i in range(100):
        A = [random.randint(1, 1000) for i in range(100)]
        N = len(A)
        ans1 = solveBrute(N, A)
        ans2 = solve(N, A)
        print(A, bin(ans1), bin(ans2))
        assert ans1 == ans2
else:
    if False:
        # Timing
        import random

        random.seed(0)
        A = [random.randint(1, 10 ** 7) for i in range(400000)]
        N = len(A)
        print(solve(N, A))


if __name__ == "__main__":
    (N,) = list(map(int, input().split()))
    A = list(map(int, input().split()))
    ans = solve(N, A)
    print(ans)
