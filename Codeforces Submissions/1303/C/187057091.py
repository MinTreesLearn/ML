from collections import Counter, deque, defaultdict
import math
from itertools import permutations, accumulate
from sys import *
from heapq import *
from bisect import bisect_left, bisect_right
from functools import cmp_to_key
from random import randint
xor = randint(10 ** 7, 10**8)
# https://docs.python.org/3/library/bisect.html
on = lambda mask, pos: (mask & (1 << pos)) > 0
lcm = lambda x, y: (x * y) // math.gcd(x,y)
rotate = lambda seq, k: seq[k:] + seq[:k] # O(n)
input = stdin.readline
'''
Check for typos before submit, Check if u can get hacked with Dict (use xor)
Observations/Notes: 
'''



for _ in range(int(input())):
    alpha = set(list("xzytabcdefghijklmnopqrsuvw"))
    s = input().strip()
    if len(s) == 1:
        print("YES")
        actual = []
        alpha.remove(s[0])
        actual.append(s[0])
        for char in alpha:
            actual.append(char)
        print("".join(actual))
        continue

    n = len(s)
    adj = [[] for _ in range(26)]
    indegree = [0] * 26
    seen = [[0] * 26 for _ in range(26)]

    for i, char in enumerate(s):
        if i + 1 < n and (seen[ord(char) - ord('a')][ord(s[i + 1]) - ord('a')] == 0 and seen[ord(s[i + 1]) - ord('a')][ord(char) - ord('a')]== 0):
            adj[ord(char) - ord('a')].append(ord(s[i + 1]) - ord('a'))
            adj[ord(s[i + 1]) - ord('a')].append(ord(char) - ord('a'))  
            indegree[ord(char) - ord('a')] += 1
            indegree[ord(s[i + 1]) - ord('a')] += 1
            seen[ord(char) - ord('a')][ord(s[i + 1]) - ord('a')] += 1
    q = []
    visited = [False] * 26
    for i in range(26):
        if indegree[i] == 1:
            q.append(i)
            visited[i] = True
            break
    
    if (len(q) == 0):
        print("NO")
        continue
    poss = True
    ans = []
    while q:
        node = q.pop()
        if indegree[node] >= 2:
            poss = False
            break

        ans.append(node)
        for nei in adj[node]:
            indegree[nei] -= 1
            if visited[nei]: 
                continue
            q.append(nei)
            visited[nei] = True

    if not poss:
        print("NO")
        continue

    actual = []
    for num in ans:
        curr = chr(num + ord('a'))
        actual.append(curr)
        alpha.remove(curr)
    
    # poss = True
    # for num in indegree:
    #     poss &= (num == 0)
   

    print("YES")
    for char in alpha:
        actual.append(char)
    print("".join(actual))