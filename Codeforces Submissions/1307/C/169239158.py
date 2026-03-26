# 2022-08-21 21:01:42.073918
# https://codeforces.com/problemset/problem/1307/C
import string
import sys
from collections import Counter, defaultdict

_DEBUG = True
if not _DEBUG:
    input = sys.stdin.readline
    # print = sys.stdout.write


def proc(s):
    n = len(s)
    c = Counter()
    t2 = defaultdict(int)
    for i, e in enumerate(s):
        for prefix in string.ascii_lowercase:
            t2[prefix + e] += c[prefix]
        c[e] += 1

    res = max(c.most_common(1)[0][1], max(t2.values()))
    return res


"""

qdpinbmcrfwxpdbfgozvvocemjruct
                      c


"""
# assert proc('usaco') == 1
# assert proc('lol') == 2
# assert proc('aaabb') == 6
# assert proc(
#     'qdpinbmcrfwxpdbfgozvvocemjructoadewegtvbvbfwwrpgyeaxgddrwvlqnygwmwhmrhaizpyxvgaflrsvzhhzrouvpxrkxfza') == 37
s = input().strip()
ans = proc(s)
print(ans)
