# Author Name: Ajay Meena
# Codeforce : https://codeforces.com/profile/majay1638
import sys
import math
import bisect
import heapq
from bisect import bisect_right
from sys import stdin, stdout
from collections import deque
# -------------- INPUT FUNCTIONS ------------------


def get_ints_in_variables(): return map(
    int, sys.stdin.readline().strip().split())


def get_int(): return int(sys.stdin.readline())


def get_ints_in_list(): return list(
    map(int, sys.stdin.readline().strip().split()))
def get_list_of_list(n): return [list(
    map(int, sys.stdin.readline().strip().split())) for _ in range(n)]


def get_string(): return sys.stdin.readline().strip()

# -------- SOME CUSTOMIZED FUNCTIONS-----------


def myceil(x, y): return (x + y - 1) // y

# -------------- SOLUTION FUNCTION ------------------


def Solution():
    # Write Your Code Here
    pass


def helper(arr, n):
    l = [0 for _ in range(n)]
    stk = deque()
    for i in range(n):
        while len(stk) and arr[stk[-1]] >= arr[i]:
            stk.pop()
        if len(stk) == 0:
            l[i] = (i+1)*arr[i]
        else:
            j = stk[-1]
            l[i] = (((i-j))*arr[i])+l[j]
        stk.append(i)
    return l


def main():
    # Take input Here and Call solution function
    n = get_int()
    arr = get_ints_in_list()
    if n == 1:
        print(arr[0])
        return
    # ans = [0 for _ in range(n)]
    l = helper(arr, n)
    r = list(reversed(helper(list(reversed(arr)), n)))
    ind = max([_ for _ in range(n)], key=lambda i: l[i]+r[i]-arr[i])
    for i in range(ind-1, -1, -1):
        arr[i] = min(arr[i], arr[i+1])
    for i in range(ind+1, n):
        arr[i] = min(arr[i], arr[i-1])
    print(*arr)


# calling main Function
if __name__ == '__main__':
    main()
