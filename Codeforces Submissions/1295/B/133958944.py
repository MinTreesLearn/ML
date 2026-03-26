import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    s = list(input().rstrip())
    a = [0]
    for i in s:
        a.append(a[-1] + (1 if i == "0" else -1))
    an = a[n]
    if an:
        ans = 0
        for i in range(n):
            if x - a[i] >= 0 and an > 0 or x - a[i] <= 0 and an < 0:
                if abs(x - a[i]) % abs(an) == 0:
                    ans += 1
    else:
        ans = -1 if x in set(a) else 0
    print(ans)