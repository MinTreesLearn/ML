t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    while n != 0:
        if n > 9:
            ans += (n//10) * 10
            n = (n - ((n//10) * 10)) + (n//10)
        else:
            ans += n
            break
    print(ans)