#! /bin/env python3

# please follow ATshayu

def main():
    n = int(input())
    m = list(map(int, input().split(' ')))
    # solve
    ans = 0
    for i in range(n):
        l, r = i - 1, i + 1
        x = m[i]
        b = [int(1e9)]*1005
        b[i] = m[i]
        while l >= 0:
            b[l] = min(m[l], b[l+1])
            x += b[l]
            l -= 1
        while r < n:
            b[r] = min(m[r], b[r-1])
            x += b[r]
            r += 1
        if x > ans:
            ans = x
            a = b
    for i in range(n): print(a[i], end=' ')
        

main()