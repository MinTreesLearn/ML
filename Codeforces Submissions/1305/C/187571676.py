from sys import stdin
input = stdin.readline

n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
if n > m: print(0); quit()
ans = 1
for i in range(n):
    for j in range(i):
        ans = ans*abs(a[i]-a[j])%m
print(ans)

# https://www.bilibili.com/read/cv8299203