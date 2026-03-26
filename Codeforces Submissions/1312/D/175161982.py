
num_inp=lambda: int(input())
arr_inp=lambda: list(map(int,input().split()))
sp_inp=lambda: map(int,input().split())
str_inp=lambda:input()
M = 998244353
n, m = map(int, input().split())
f = {}
f[0] = 1
for i in range(1, m+1):
    f[i] = f[i-1]*i%M
ans = ((n-2)*pow(2, n-3, M)*f[m]*pow(f[n-1]*f[m-n+1], M-2, M))%M
print(ans)