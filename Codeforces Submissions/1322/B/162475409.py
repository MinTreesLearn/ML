import sys
input = sys.stdin.buffer.readline

from functools import reduce
def __flatten(A):
    return reduce(lambda x, y: x+y, A)

def radix(a):
    digits = len(str(max(a)))
    for i in range (digits):
        b = [[] for _ in range (10)]
        e = pow(10, i)
        for j in a:
            num = (j//e)%10
            b[num].append(j)
        a *= 0
        for l in b:
            a += l


N = int(input())
a = list(map(int, input().split()))
     

res = 0
radix(a)
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