# Author Name: Ajay Meena
# Codeforce : https://codeforces.com/profile/majay1638
import sys
import math
import bisect
import heapq
from bisect import bisect_right
from sys import stdin, stdout

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


def main():
    # Take input Here and Call solution function
    n = get_int()
    s = get_string()
    stk = []
    ans = 0
    for c in s:
        if len(stk) == 0:
            stk.append(c)
        else:
            if stk[-1] == "(" and c == ")":
                stk.pop()
            elif stk[-1] != c:
                stk.pop()
                ans += 2
            else:
                stk.append(c)
    if len(stk):
        print(-1)
    else:
        print(ans)


# calling main Function
if __name__ == '__main__':
    main()
