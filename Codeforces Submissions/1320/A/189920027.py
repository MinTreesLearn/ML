#! /bin/env python3

n = int(input())
b = list(map(int, input().split(' ')))

ans = -1000
ATshayu = {}
for i in range(n):
    v = b[i] - i
    try:
        ATshayu[v] += b[i]
    except:
        ATshayu[v] = b[i]
    finally:
        ans = max(ans, ATshayu[v])
print(ans)