t = int(input())

for i in range(t):
    n = int(input())
    number = (input().split())
    ans = 0
    for x in number:
        if int(x) % 2 == 0:
            ans += 1
    if (ans == n) or (ans == 0 and n % 2 == 0):
        print("NO")
    else:
        print("YES")
