import math
n, m = [int(x) for x in input().split()]
s, t = input().split(), input().split()

lowermn = min(n, m)

ip = int(input())

for _ in range(ip):
    year = int(input()) - 1
    print(s[year%n] + t[year%m])
    