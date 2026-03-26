import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())

def solve():
    n, m = [int(x) for x in input().split()]
    min_t = m
    max_t = m
    prev = 0
    t = [0]*n
    l = [0]*n
    h = [0]*n
    for i in range(n):
        t[i],l[i],h[i] = get_ints()
    flag = True
    for i in range(n):
        max_t += t[i] - prev
        min_t -= t[i] - prev
        if max_t < l[i] or min_t > h[i]:
            flag = False
            break
        max_t = min(h[i], max_t)
        min_t = max(l[i], min_t)
        prev = t[i]

    result = "YES" if flag else "NO"
    print(result)
    return

t = int(input())
for i in range(t):
    solve()