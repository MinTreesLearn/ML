from collections import defaultdict
from sys import stdin
input = stdin.buffer.readline

def func():
    if n == 1:
        print(a[0])
    else:
        bits = defaultdict(int)
        for i in range(65):
            for j in range(n):
                if 1 << i & a[j]:
                    bits[i] += 1

        up = -1
        for i in range(65):
            if bits[i] == 1:
                up = i

        if up == -1:
            print(*a)
        else:
            ind = -1
            for i in range(n):
                if 1 << up & a[i]:
                    ind = a[i]
                    break

            a.remove(ind)
            print(ind, *a)


n = int(input())
a = list(map(int, input().split()))
func()
