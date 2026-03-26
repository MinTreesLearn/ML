import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    s = input()

    min_r = s
    k = 1
    for i in range(1, n):
        if i % 2 == n % 2:
            temp = s[i:] + s[:i]
        else:
            temp = s[i:] + s[:i][::-1]

        if temp < min_r:
            min_r = temp
            k = i + 1

    print(min_r)
    print(k)