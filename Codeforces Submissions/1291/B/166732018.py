import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))

    if n % 2 == 1:
        ip = True
        for i in range(n // 2):
            if li[i] < i or li[n - 1 - i] < i:
                ip = False
                break
        if li[n // 2] < n // 2:
            ip = False

        if ip:
            print('Yes')
        else:
            print('No')
    else:
        ip = True
        for i in range(n // 2):
            if li[i] < i or li[n - 1 - i] < i:
                ip = False
                break

        mid_left = n // 2 - 1
        mid_right = mid_left + 1

        min_cri = n // 2 - 1

        if not (li[mid_left] >= min_cri and li[mid_right] >= min_cri + 1 or li[mid_left] >= min_cri + 1 and li[mid_right] >= min_cri):
            ip = False

        if ip:
            print('Yes')
        else:
            print('No')