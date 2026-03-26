import sys
input = sys.stdin.buffer.readline

from collections import deque

def radix_sort(a):
    l = len(a)
    mx = max(a)
    m = 0
    while mx > 0:
        mx = mx // 10
        m += 1
    bucket = [deque([]) for _ in range (10)]
    for j in range (m):
        div = pow(10, j)
        for i in range (l):
            bucket[(a[i]//div)%10].append(a[i])
        a *= 0
        for i in range (10):
            while len(bucket[i]) > 0:
                a.append(bucket[i].popleft())


N = int(input())
a = list(map(int, input().split()))
     

res = 0
radix_sort(a)
for k in range(max(a).bit_length(), -1, -1):
    z = 1 << k
    c = 0
     
    j = jj = jjj = N - 1
    for i in range(N):
        while j >= 0 and a[i] + a[j] >= z: j -= 1
        while jj >= 0 and a[i] + a[jj] >= z << 1: jj -= 1
        while jjj >= 0 and a[i] + a[jjj] >= z * 3: jjj -= 1
     
        c += N - 1 - max(i, j) + max(i, jj) - max(i, jjj)
     
    res += z * (c & 1)
    for i in range(N): a[i] = min(a[i] ^ z, a[i])
    a.sort()
      #print(res, a, c)
print(res)