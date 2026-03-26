n = int(input())
ans = 0
x = n
for i in range(n):
    ans += 1 / x
    x -= 1
print(ans)