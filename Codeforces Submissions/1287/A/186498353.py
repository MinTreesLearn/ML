t = int(input())
for _ in range(t):
    k = int(input())
    s = input()
    ans = 0
    while "AP" in s:
        s = s.replace("AP", "AA")
        ans += 1
    print(ans)