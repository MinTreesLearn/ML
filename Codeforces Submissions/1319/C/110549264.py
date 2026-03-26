import math
from collections import deque
from sys import stdin, stdout, setrecursionlimit
from string import ascii_letters
from decimal import *
letters = ascii_letters[:26]
from collections import defaultdict
#from functools import reduce
#input = stdin.readline
#print = stdout.write

def check(a, b):
    return letters.index(b) == letters.index(a) - 1


was = int(input())
arr = list(input())
for i in range(len(letters) -1, -1, -1):
    changes = True
    while changes:
        changes = False
        n = len(arr)
        for g in range(n):
            if arr[g] == letters[i] and ((g > 0 and check(arr[g], arr[g - 1])) or (g < n - 1 and check(arr[g], arr[g + 1]))):
                arr.pop(g)
                changes = True
                break
print(was - len(arr))