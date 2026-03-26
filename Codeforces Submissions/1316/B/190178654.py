#! /bin/env python3

def cmp(k1, k2):
    p1, p2 = k1, k2
    d1, d2 = 1 , 1
    for i in range(n):
        if s[p1] > s[p2]: return  1
        if s[p1] < s[p2]: return -1
        if p1 == n:
            if (n-k1+1)&1 == 1:
                p1, d1 = k1, -1
            else: p1 = 0
        if p2 == n:
            if (n-k2+1)&1 == 1:
                p2, d2 = k2, -1
            else: p2 = 0
        p1 += d1
        p2 += d2
    return 0

t = int(input())

for i in range(t):
    n = int(input())
    s = '0' + input()
    # solve
    mn = 1
    for j in range(2, n+1):
        if cmp(mn, j) > 0: mn = j
    ATshayu, d = mn, 1
    for j in range(n):
        print(s[ATshayu], end='')
        if ATshayu == n:
            if (n-mn+1)&1 == 1:
                ATshayu, d = mn, -1
            else: ATshayu = 0
        ATshayu += d
    print('\n'+str(mn))
