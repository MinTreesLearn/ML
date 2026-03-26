#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Codeforces/612/div1_b.py
 @author SHawnHardy
 @date 2020-01-08
 @copyright MIT License
"""

n = int(input())
graph = [[] for _ in range(n + 1)]
ci = [0]


def solve(x):
    rst = []
    if graph[x]:
        for s in graph[x]:
            rst.extend(solve(s))

    if len(rst) < ci[x]:
        raise ValueError

    rst.insert(ci[x], x)
    return rst


for i in range(1, n + 1):
    p, c = map(int, input().split())
    graph[p].append(i)
    ci.append(c)

try:
    ans = solve(graph[0][0])
except ValueError:
    print("NO")
else:
    print("YES")
    for i in range(1, n + 1):
        print(ans.index(i) + 1, end=' ')
