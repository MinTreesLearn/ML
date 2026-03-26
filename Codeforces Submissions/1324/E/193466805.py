from bisect import bisect_left, bisect_right
from collections import Counter, deque
from functools import lru_cache
from math import factorial, comb, sqrt, gcd, lcm
from copy import deepcopy
import heapq

from sys import stdin, stdout

# 加快读入速度, 但是注意后面的换行符(\n)
# 如果是使用 input().split() 或者 int(input()) 之类的, 换行符就去掉了
input = stdin.readline

# 由记忆化搜索改 dp
def f(cur_index, s):
    if cur_index == len(L):
        return 0
    s += L[cur_index]
    return max(f(cur_index + 1, s), f(cur_index + 1, s - 1)) + (1 if left <= s % h <= right else 0)


def main():
    n, h, left, right = map(int, input().split())
    L = list(map(int, input().split()))

    dp = [[0] * h for _ in range(n)]
    walked = [[False] * h for _ in range(n)]

    walked[0][L[0] % h] = True
    if left <= L[0] % h <= right:
        dp[0][L[0] % h] = 1

    walked[0][(L[0] - 1) % h] = True
    if left <= (L[0] - 1) % h <= right:
        dp[0][(L[0] - 1) % h] = 1

    for i in range(len(L) - 1):
        for j in range(h):
            if walked[i][j] is True:
                walked[i + 1][(j + L[i + 1]) % h] = True
                dp[i + 1][(j + L[i + 1]) % h] = max(dp[i + 1][(j + L[i + 1]) % h],
                                                    dp[i][j] + (1 if left <= (j + L[i + 1]) % h <= right else 0))

                walked[i + 1][(j + L[i + 1] - 1) % h] = True
                dp[i + 1][(j + L[i + 1] - 1) % h] = max(dp[i + 1][(j + L[i + 1] - 1) % h],
                                                        dp[i][j] + (1 if left <= (j + L[i + 1] - 1) % h <= right else 0))

    ans = 0
    for j in range(h):
        ans = max(ans, dp[-1][j])
    print(ans)



if __name__ == "__main__":
    main()
