import io
import os
from array import array

# Rewrote in C++

DEBUG = False


if DEBUG:
    from functools import lru_cache

    def solveTopDown(N, P, K, audienceScore, playerScore):
        # Choose P players and K audience members from N people
        assert len(audienceScore) == len(playerScore) == N

        # Sort both scores by audience score from largest to smallest
        scores = sorted(zip(audienceScore, playerScore), reverse=True)
        audienceScore = [a for a, p in scores]
        playerScore = [p for a, p in scores]

        @lru_cache(maxsize=None)
        def f(n, mask):
            # Return best score using up to the nth person with mask of positions used
            # Since we sorted by audience scores, we can take everyone not used in mask until exceed K
            if n == 0:
                # Single person
                if mask == 0:
                    # Not a player so must be an audience member
                    return audienceScore[n]
                else:
                    # Must be player at some position
                    for pos in range(P):
                        if mask == 1 << pos:
                            return playerScore[n][pos]
                    # Otherwise invalid
                    return float("-inf")

            # nth is neither audience nor player
            best = f(n - 1, mask)

            # Check if nth could be an audience member
            num = n + 1  # there are n + 1 people in 0 to n inclusive
            numPlayers = _popcount[mask]  # number of players in the mask
            if num - numPlayers <= K:
                # The audience members are always the first K not in mask and we are within that K
                best += audienceScore[n]

            # Try placing as a player, audience remains the same
            for pos in range(P):
                if (1 << pos) & mask:
                    best = max(best, playerScore[n][pos] + f(n - 1, mask - (1 << pos)))

            return best

        best = 0
        for i in range(N):
            for mask in range(1 << P):
                # print(i, bin(mask)[2:])
                val = f(i, mask)
                # print("\t", val)
                best = max(best, val)

        return best


def popcount(i):
    # Python doesn't have __builtin_popcount
    # https://stackoverflow.com/a/407758
    assert 0 <= i < 0x100000000
    i = i - ((i >> 1) & 0x55555555)
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
    return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xFFFFFFFF) >> 24


_popcount = []
for mask in range(1 << 7):
    _popcount.append(popcount(mask))

maskToPos = []
for mask in range(1 << 7):
    maskToPos.append([i for i in range(7) if mask & (1 << i)])


negInf = float("-inf")


def solve(N, P, K, audienceScore, playerScore):
    scores = sorted(zip(audienceScore, playerScore), reverse=True)
    scoresA = [0.0 for i in range(N)]
    scoresP = [0.0 for i in range(7 * N)]
    for i, (a, ps) in enumerate(scores):
        scoresA[i] = float(a)
        for j, p in enumerate(ps):
            scoresP[7 * i + j] = float(p)

    f = [negInf for mask in range(1 << P)]
    nextF = [negInf for mask in range(1 << P)]

    f[0] = scoresA[0]
    for pos in range(P):
        f[1 << pos] = scoresP[pos]

    for n in range(1, N):
        for mask in range(1 << P):
            best = f[mask]
            if n - _popcount[mask] < K:
                best += scoresA[n]
            for pos in maskToPos[mask]:
                best = max(best, scoresP[7 * n + pos] + f[mask - (1 << pos)])
            nextF[mask] = best

        f, nextF = nextF, f

    return int(max(f))


if DEBUG:
    from random import randint

    N = 100000
    P = 7
    K = 90000
    audienceScore = [randint(1, 100) for i in range(N)]
    playerScore = [[randint(1, 100) for j in range(7)] for i in range(N)]
    ans = solve(N, P, K, audienceScore, playerScore)
    if False:
        assert ans == solveTopDown(N, P, K, audienceScore, playerScore)
    exit()

if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, P, K = list(map(int, input().split()))
    audienceScore = [int(x) for x in input().split()]
    playerScore = [[int(x) for x in input().split()] for i in range(N)]
    ans = solve(N, P, K, audienceScore, playerScore)
    print(ans)
