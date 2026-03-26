# 2022-09-04 15:27:04.802963
# https://codeforces.com/problemset/problem/1301/C
import sys

_DEBUG = False
# _DEBUG = True
if not _DEBUG:
    input = sys.stdin.readline
    print = sys.stdout.write

"""
6 2

7 // 3 == 2


001001 3 + 3

001010 3 + 1 + 1 

"""


def proc(n, m):
    total_num = n * (n + 1) // 2

    num_of_zero = n - m
    group_count = m + 1

    num_per_group = num_of_zero // group_count

    remains = num_of_zero % group_count

    return total_num - num_per_group * (num_per_group + 1) // 2 * group_count - remains * (num_per_group + 1)


if _DEBUG:
    assert proc(3, 1) == 4
    assert proc(2, 1) == 2
    assert proc(5, 1) == 9
    assert proc(3, 3) == 6
    assert proc(4, 0) == 0
    assert proc(5, 2) == 12

    # fin = open('input.txt')
    # fou = open('output.txt')
    #
    # fin.readline()
    # for line in fin.readlines():
    #     n, m = map(int, line.split())
    #
    #     expected = int(fou.readline())
    #
    #     if proc(n, m) != expected:
    #         print('proc({}, {}) != {} !!'.format(n, m, expected))

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = proc(n, m)
    if not _DEBUG:
        print(str(ans) + '\n')
    else:
        print(ans)
