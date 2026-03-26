#!/usr/bin/env python3
def solution(n: int, m: int, k: int, soldier: list) -> int:
    arr = soldier
    max_val = None
    pop_num_r0 = min(k, m-1)
    for left_r0 in range(pop_num_r0+1):
        right_r0 = n-pop_num_r0+left_r0
        # print('l0, r0:', left_r0, right_r0)
        len_arr_r0 = right_r0 - left_r0
        pop_num_r1 = m - 1 - pop_num_r0
        val = None
        for left_r1 in range(left_r0, left_r0 + pop_num_r1+1):
            right_r1 = len_arr_r0-pop_num_r1 + left_r1
            # print('l1, r1:', left_r1, right_r1)
            if val is None:
                val = max(arr[left_r1], arr[right_r1-1])
            val = min(max(arr[left_r1], arr[right_r1-1]), val)
        if max_val is None:
            max_val = val
        max_val = max(val, max_val)
    return max_val


if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        n, m, k = [int(i) for i in input().split()]
        arr = [int(i) for i in input().split()]
        answer = solution(n, m, k, arr)
        print(answer)
