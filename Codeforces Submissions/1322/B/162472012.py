import sys
input = sys.stdin.buffer.readline
    
from collections import deque
def countingSort(arr, exp1): 
    n = len(arr)
    output = [0] * (n)
    count = [0] * (10)
    for i in range(0, n):
        index = arr[i] // exp1
        count[index % 10] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    i = n - 1
    while i >= 0:
        index = arr[i] // exp1
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1
    i = 0
    for i in range(0, len(arr)):
        arr[i] = output[i]

def radixSort(arr):
    max1 = max(arr)
    exp = 1
    while max1 / exp >= 1:
        countingSort(arr, exp)
        exp *= 10

N = int(input())
a = list(map(int, input().split()))
     
res = 0
radixSort(a)
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