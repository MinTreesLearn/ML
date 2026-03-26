n = int(input())
a = {}
inp = list(map(int, input().split()))
for c in range(1, n + 1):
    b = inp[c - 1]
    if b - c in a:
        a[b - c] += b
    else:
        a[b - c] = b
print(max(a.values()))