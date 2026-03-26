n, m = list(map(int, input().split()))

MOD = 10**9 + 7
# since indexes are 0 based, we will use n+1 and m+1 in the dp arrays.
dp_a = [[0 for _ in range(n)] for _ in range(m)]
dp_b = [[0 for _ in range(n)] for _ in range(m)]

# setting the base state
for j in range(0, n):
    dp_a[0][j] = 1

# populating the dp_a table
for i in range(1, m):
    for j in range(0, n):
        dp_a[i][j] += dp_a[i][j - 1] + dp_a[i - 1][j]
        dp_a[i][j] %= MOD

# populating the dp_b table
for i in range(0, m):
    for j in range(0, n):
        dp_b[i][j] += dp_b[i][j - 1] + dp_a[i][j]
        dp_b[i][j] %= MOD

# calculating the final result
ans = 0
for j in range(0, n):
    # If last element of array a is j, then array be has n-j numbers avalilable.
    ans += (dp_a[m-1][j] * dp_b[m-1][n-j-1]) %MOD
    ans %= MOD

print(ans%MOD)