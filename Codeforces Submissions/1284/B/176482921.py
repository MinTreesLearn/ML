from bisect import bisect_right


def is_seq(s, t):
    return (s != t[::-1])


n = int(input())

count = 0

mx, mn = [], []

for _ in range(n):
    _, *item = map(int, input().split())
    if item == sorted(item, reverse=1):
        mx.append(item[-1])
        mn.append(item[0])

mn.sort()

for i in mx:
    count += bisect_right(mn, i)
print(n*n - count)
