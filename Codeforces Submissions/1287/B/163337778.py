# 2022-07-03T13:40:19Z
from collections import defaultdict, Counter

n, k = map(int, input().split())
cards = []
for _ in range(n):
    cards.append(input())

c = Counter(cards)

ans = 0


def another(fa, fb):
    if 'S' != fa and 'S' != fb:
        return 'S'
    if 'E' != fa and 'E' != fb:
        return 'E'
    return 'T'


cards = list(set(cards))
n = len(cards)
ans = 0

visited = set()
for i in range(n - 2):
    ci = cards[i]
    ans += c[ci] * (c[ci] - 1) // 2

    for j in range(i + 1, n - 1):
        cj = cards[j]

        expected_card = ''

        for f in range(k):
            if ci[f] == cj[f]:  # should be same
                expected_card += ci[f]
            else:
                expected_card += another(ci[f], cj[f])

        key = ''.join(sorted((ci, cj, expected_card)))
        if key in visited:
            continue
        visited.add(key)

        if expected_card in c:
            ans += c[expected_card]

            if ci == expected_card:
                ans -= 1
            if cj == expected_card:
                ans -= 1

print(ans)
