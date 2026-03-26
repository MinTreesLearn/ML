# from bisect import bisect_left, bisect_right
from collections import Counter, deque
# from functools import lru_cache
# from math import factorial, comb, sqrt, gcd, lcm
# from copy import deepcopy
# import heapq
#
# from sys import stdin, stdout

# 加快读入速度, 但是注意后面的换行符(\n)
# 如果是使用 input().split() 或者 int(input()) 之类的, 换行符就去掉了
# input = stdin.readline


def main():
    n = int(input())
    L = list(map(int, input().split()))
    dic = {}
    pre = [0]
    # for i in range(len(L)):
    #     pre.append(pre[-1] + L[i])

    for i in range(len(L)):
        flag = 0
        for j in range(i, len(L)):
            flag += L[j]
            if flag not in dic.keys():
                dic[flag] = [[i + 1, j + 1]]
            else:
                dic[flag].append([i + 1, j + 1])

    ans_len = -1
    ans = []
    for key, value in dic.items():
        value.sort(key=lambda x:x[1])
        flag = [value[0]]
        for i in range(1, len(value)):
            if value[i][0] > flag[-1][1]:
                flag.append(value[i])
        if len(flag) > ans_len:
            ans_len = len(flag)
            ans = flag
    print(ans_len)
    for i in ans:
        print(*i)



if __name__ == "__main__":
    main()
