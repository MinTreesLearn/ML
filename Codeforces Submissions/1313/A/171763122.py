import itertools
import sys

input = sys.stdin.readline

for _ in range(int(input())):
    data = sorted(map(int, input().split()), reverse=True)

    cases = []
    for i in range(3):
        tmp = list(itertools.combinations([0, 1, 2], i + 1))
        cases.append(tmp)

    cnt = 0
    for i in range(3):
        for j in cases[i]:
            ans = True
            for k in j:
                if not data[k]:
                    ans = False
                    break
            if ans:
                for k in j:
                    data[k] -= 1
                cnt += 1

    print(cnt)
