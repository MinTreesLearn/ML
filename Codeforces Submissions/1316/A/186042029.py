def solution():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]

    for i in range(1, n):
        if a[0] + a[i] > m:
            dif = m - a[0]
            a[0] += dif; a[i] -= dif
        else:
            a[0] += a[i]; a[i] = 0

    print(a[0])
    
c = int(input())

for ciclo in range(c):
    solution()
