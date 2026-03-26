import io
import os

from collections import Counter, defaultdict, deque

alpha = "abcdefghijklmnopqrstuvwxyz"
assert len(alpha) == 26


def solve(S, Q, queries):
    lettersToPref = [[0] for i in range(26)]

    for i, x in enumerate(S):
        for i, c in enumerate(alpha):
            if c == x:
                lettersToPref[i].append(lettersToPref[i][-1] + 1)
            else:
                lettersToPref[i].append(lettersToPref[i][-1] + 0)
    ans = []
    for l, r in queries:
        r += 1
        if r - l == 1:
            # Single character always work
            ans.append("Yes")
            continue
        numUnique = 0
        for i in range(26):
            count = lettersToPref[i][r] - lettersToPref[i][l]
            # assert count == sum(1 for c in S[l:r] if ord(c) - ord('a') == i)
            if count:
                numUnique += 1

        assert r - l > 1
        if numUnique == 1:
            ans.append("No")
            continue

        assert numUnique >= 2
        if S[l] != S[r - 1]:
            # Can always put last character all in front, won't reach same count for any prefix until end
            ans.append("Yes")
            continue
        
        assert S[l] == S[r - 1]
        if numUnique >= 3:
            ans.append("Yes")
            continue



        ans.append("No")
    return "\n".join(ans)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    S = input().decode().rstrip()
    (Q,) = [int(x) for x in input().split()]
    queries = [
        [int(x) - 1 for x in input().split()] for i in range(Q)
    ]  # zero indexed, inclusive both l,r
    ans = solve(S, Q, queries)
    print(ans)
