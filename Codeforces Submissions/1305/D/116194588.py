from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
# stdout.flush()
# import string
# characters = string.ascii_lowercase
# digits = string.digits
# setrecursionlimit(int(1e6))
# dir = [-1,0,1,0,-1]
# moves = 'NESW'
from random import shuffle, randint
inf = float('inf')
from functools import cmp_to_key
from collections import defaultdict as dd
from collections import Counter, deque
from heapq import *
import math
from math import floor, ceil, sqrt
def geti(): return map(int, input().strip().split())
def getl(): return list(map(int, input().strip().split()))
def getis(): return map(str, input().strip().split())
def getls(): return list(map(str, input().strip().split()))
def gets(): return input().strip()
def geta(): return int(input())
def print_s(s): stdout.write(s+'\n')

def query(u, v, q):
    q[0] += 1
    print("? {} {}".format(u, v))
    stdout.flush()
    now = geta()
    if now == -1:
        exit()
    return now

def solve():
    n = geta()
    q = [0]
    limit = n//2
    edges = dd(list)
    for i in range(n-1):
        u, v = geti()
        edges[u].append(v)
        edges[v].append(u)
    distance = dd(int)
    maxi = [-inf]
    def dfs(root, dist = 0, par = None):
        if maxi[0] == -inf or distance[maxi[0]] < dist:
            maxi[0] = root
        distance[root] = dist
        for node in edges[root]:
            if node != par:
                dfs(node, dist + 1, root)

    leaf = set()
    leaves = set()
    for i in range(1, n+1):
        if len(edges[i]) == 1 and i not in leaf:
            maxi[0] = -inf
            distance.clear()
            dfs(i)
            leaf.add(i)
            leaf.add(maxi[0])
            leaves.add(i)
            leaves.add(maxi[0])
    leaf = list(leaf)
    while len(leaf) != 1 and q[0] < limit:
        new = set()
        for i in range(1, len(leaf), 2):
            if q[0] > limit:
                break
            now = query(leaf[i], leaf[i-1], q)
            if now in leaves:
                print("!", now)
                stdout.flush()
                exit()
            new.add(now)
        if len(leaf) & 1:
            new.add(leaf[-1])
        leaf = list(new)
    print("!", leaf[0])
    stdout.flush()




if __name__=='__main__':
    solve()
#
# 5 5
# 1 2
# 1 3
# 4 1
# 4 5

#      5
#      |
#      4
#     /
#    1
#  /   \
# 2     3
