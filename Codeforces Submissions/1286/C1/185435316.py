import sys, os
input = sys.stdin.buffer.readline

n = int(input())
a, b = "?".encode(), "!".encode()
if n == 1:
    os.write(1, b"%s %d %d\n" % (a, 1, 1))
    s = input().rstrip().decode()
    ans = ("! " + s).encode()
    os.write(1, b"%s\n" % ans)
    exit()
cnt1 = [[0] * 26 for _ in range(n + 1)]
os.write(1, b"%s %d %d\n" % (a, 1, n))
for _ in range(n * (n + 1) // 2):
    s = list(input().rstrip())
    c = cnt1[len(s)]
    for i in s:
        c[i - 97] += 1
cnt2 = [[0] * 26 for _ in range(n + 1)]
os.write(1, b"%s %d %d\n" % (a, 1, n - 1))
for _ in range(n * (n - 1) // 2):
    s = list(input().rstrip())
    c = cnt2[len(s)]
    for i in s:
        c[i - 97] += 1
ans = [-1] * n
c1, c2 = cnt1[n], cnt2[n - 1]
for i in range(26):
    if c1[i] ^ c2[i]:
        ans[-1] = i
        break
for i in range(2, (n + 1) // 2 + 1):
    x = [min(j + 1, n - j, i) for j in range(n)]
    c = cnt1[i]
    for j in range(n):
        if ans[j] ^ -1:
            c[ans[j]] -= x[j]
    for j in range(26):
        if c[j] % i:
            ans[i - 2] = j
            break
    x = [min(j + 1, n - 1 - j, i) for j in range(n - 1)]
    c = cnt2[i]
    for j in range(n - 1):
        if ans[j] ^ -1:
            c[ans[j]] -= x[j]
    for j in range(26):
        if c[j] % i:
            ans[-i] = j
            break
if not n % 2:
    c = cnt1[n]
    for i in ans:
        if i ^ -1:
            c[i] -= 1
    for i in range(26):
        if c[i]:
            ans[n // 2 - 1] = i
            break
ans = ("! " + "".join(chr(i + 97) for i in ans)).encode()
os.write(1, b"%s\n" % ans)
exit()