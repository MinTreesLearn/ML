#!/usr/bin/env python3

n = int(input())
for _ in range(n):
    n, m, k = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]
    total_pop = m - 1
    max_val = None
    pop_num_r0 = min(k, m-1)
    for left_r0 in range(pop_num_r0+1):
        _arr = arr[left_r0:len(arr)-pop_num_r0+left_r0]
        pop_num_r1 = m - 1 - pop_num_r0
        val = None
        for left_r1 in range(pop_num_r1+1):
            __arr = _arr[left_r1:len(_arr)-pop_num_r1+left_r1]
            if val is None:
                val = max(__arr[0], __arr[-1])
            val = min(max(__arr[0], __arr[-1]), val)
        if max_val is None:
            max_val = val
        max_val = max(val, max_val)
    print(max_val)
