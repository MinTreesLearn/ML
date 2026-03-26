import bisect
import collections
import copy
import enum
import functools
import heapq
import itertools
import math
import random
import re
import sys
import time
import string
from typing import List
sys.setrecursionlimit(3001)

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,s = input().split()
    n = int(n)
    l1 = list(range(n,0,-1))
    l2 = list(range(1,n+1))
    i = 0
    while i<n-1:
        if s[i]=="<":
            st = i
            while i<n-1 and s[i]=="<":
                i+=1
            l1[st:i+1] = l1[st:i+1][::-1]
        i+=1
    i = 0
    while i<n-1:
        if s[i]=='>':
            st = i
            while i<n-1 and s[i]=='>':
                i+=1
            l2[st:i+1] = l2[st:i+1][::-1]
        i+=1
    print(*l1)
    print(*l2)