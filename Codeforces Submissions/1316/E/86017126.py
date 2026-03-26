import io
import os


# PSA:
# The key optimization that made this pass was to avoid python big ints by using floats (which have integral precision <= 2^52)
# None of the other optimizations really mattered in comparison.
# Credit for this trick goes to pajenegod: https://codeforces.com/blog/entry/77309?#comment-622486

popcount = []
for mask in range(1 << 7):
    popcount.append(bin(mask).count("1"))

maskToPos = []
for mask in range(1 << 7):
    maskToPos.append([i for i in range(7) if mask & (1 << i)])


inf = float("inf")


def solve(N, P, K, audienceScore, playerScore):
    scores = sorted(zip(audienceScore, playerScore), reverse=True)
    scoresA = [0.0 for i in range(N)]
    scoresP = [0.0 for i in range(7 * N)]
    for i, (a, ps) in enumerate(scores):
        scoresA[i] = float(a)
        for j, p in enumerate(ps):
            scoresP[7 * i + j] = float(p)

    f = [-inf for mask in range(1 << P)]
    nextF = [-inf for mask in range(1 << P)]

    f[0] = scoresA[0]
    for pos in range(P):
        f[1 << pos] = scoresP[pos]

    for n in range(1, N):
        for mask in range(1 << P):
            best = f[mask]
            if n - popcount[mask] < K:
                best += scoresA[n]
            for pos in maskToPos[mask]:
                best = max(best, scoresP[7 * n + pos] + f[mask - (1 << pos)])
            nextF[mask] = best

        f, nextF = nextF, f

    return int(max(f))


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, P, K = list(map(int, input().split()))
    audienceScore = [int(x) for x in input().split()]
    playerScore = [[int(x) for x in input().split()] for i in range(N)]
    ans = solve(N, P, K, audienceScore, playerScore)
    print(ans)
