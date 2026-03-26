# NOT MY CODE
# https://codeforces.com/contest/1324/submission/73179914
 
## PYRIVAL BOOTSTRAP
# https://github.com/cheran-senthil/PyRival/blob/master/pyrival/misc/bootstrap.py
# This decorator allows for recursion without actually doing recursion
from types import GeneratorType
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
######################
 
 
import math
from bisect import bisect_left, bisect_right
from sys import stdin, stdout, setrecursionlimit
from collections import Counter
input = lambda: stdin.readline().strip()
print = stdout.write
#setrecursionlimit(10**6)
 
n = int(input())
ls = list(map(int, input().split()))
children = {}
for i in range(1, n+1):
    children[i] = []
for i in range(n-1):
    a, b = map(int, input().split())
    children[a].append(b)
    children[b].append(a)
 
parent = [-1]
ans = [-1]
for i in range(1, n+1):
    parent.append(-1)
    ans.append(-1)
 
visited = [False]
for i in range(1, n+1):
    visited.append(False)
 
@bootstrap
def dfs(node):
    visited[node] = True
    ans[node] = 1 if ls[node-1] else -1
    for i in children[node]:
        if not visited[i]:
            parent[i] = node
            tmp = (yield dfs(i))
            if tmp>0:
                ans[node]+=tmp
    ans[node] = max(ans[node], 1 if ls[node-1] else -1)
    yield ans[node]
dfs(1)
 
visited = [False]
for i in range(1, n+1):
    visited.append(False)
 
@bootstrap
def dfs(node):
    visited[node] = True
    if node!=1:
        ans[node] = max(ans[node], ans[parent[node]] if ans[node]>=0 else ans[parent[node]]-1)
    for i in children[node]:
        if not visited[i]:
            yield dfs(i)
    yield
dfs(1)
 
for i in range(1, n+1):
    print(str(ans[i])+' ')
print('\n')