import math
from collections import *

def solve():
    n, m = map(int, input().split())
    s = input()
    a = [int(i) for i in input().split()]
    ans = [0 for i in range(n)]
    for i in range(len(a)):
        ans[a[i]-1] += 1
    for i in range(n-1, 0, -1):
        ans[i-1] += ans[i]
    d = defaultdict(int)
    for i in range(len(s)):
        d[s[i]] += (ans[i]+1)
    for i in range(ord("a"), ord("z")+1):
        if d.get(chr(i), 0) != 0:
            print(d.get(chr(i), 0), end = " ")
        else:
            print(0, end = " ")
    print()

t = int(input())
for _ in range(t):
    solve()
# solve()
