import sys
 

reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__
 
n, m = map(int, input().split())
 
def limit(n):
    if n < 3:
        return 0
    if n ^ 1:
        return ((n - 1) * (n - 1)) >> 2
    else:
        return ((n - 2) * n) >> 2
 
if m > limit(n):
    print(-1)
    sys.exit()
elif not m:
    ans = [10 ** 8 + 1]
    while len(ans) < n:
        ans.append(ans[-1] + 10 ** 4)
    print(*ans)
    sys.exit()

L = 3
R = n + 1
while L + 1 < R:
    k = (L + R) >> 1
    if limit(k) > m:
        R = k
    else:
        L = k
k = L
ans = list(range(1, k + 1))

req = m - limit(k)
if req > 0:
    ans.append(ans[-1] + ans[-2 * req])
    k += 1
big_num = 10 ** 8 + 1
for i in range(k, n):
    ans.append(big_num)
    big_num += 10 ** 4

print(*ans)
