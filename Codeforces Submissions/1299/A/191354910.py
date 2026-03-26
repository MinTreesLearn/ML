#! /bin/env python3

# please follow ATshayu

def main():
    cnt = [0] * 35

    n = int(input())
    a = list(map(int, input().split(' ')))
    # solve
    for ele in a:
        for j in range(32):
            if ele & (1<<j) != 0:
                cnt[j] += 1
    mx, ind = 0, 0
    for i, ele in enumerate(a):
        val = 0
        for j in range(32):
            if ele&(1<<j) and cnt[j] == 1:
                val += 1 << j
        if val > mx:
            mx, ind = val, i
    a[0], a[ind] = a[ind], a[0]
    for ele in a: print(ele, end=' ')

main()