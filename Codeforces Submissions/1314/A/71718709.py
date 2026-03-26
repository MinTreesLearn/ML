from operator import itemgetter
from collections import deque
import heapq
import sys
input = sys.stdin.readline


n = int(input())
a = list(map(int, input().split())) + [10**18]
t = list(map(int, input().split())) + [1]

info = [(t[i], a[i]) for i in range(n + 1)]
info = sorted(info, key=itemgetter(0), reverse=True)
info = sorted(info, key=itemgetter(1))

ans = 0

q = []
max_now = 0
i = 0
while i < n + 1:
    while True:
        if info[i][1] <= max_now:
            tmp_t, tmp_a = info[i]
            heapq.heappush(q, (-tmp_t, tmp_a))
            i += 1
        else:
            break
    if q:
        tmp_t, tmp_a = heapq.heappop(q)
        ans += -tmp_t * (max_now - tmp_a)
        max_now += 1
    else:
        max_now = info[i][1] + 1
        i += 1
print(ans)