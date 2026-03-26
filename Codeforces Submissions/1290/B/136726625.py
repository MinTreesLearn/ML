import sys
input = sys.stdin.readline

s = [ord(i)-97 for i in input().strip()]
p = [[0] for i in range(26)]
for i in range(len(s)):
    for j in range(26):
        p[j].append(p[j][-1])
    p[s[i]][i+1] += 1
for z in range(int(input())):
    l, r = map(int, input().split())
    if l == r:
        print('Yes')
        continue
    x = 0
    for i in range(26):
        cur = p[i][r]-p[i][l-1]
        if cur:
            x += 1
    if x == 1 or (x == 2 and s[l-1] == s[r-1]):
        print('No')
    else:
        print('Yes')
