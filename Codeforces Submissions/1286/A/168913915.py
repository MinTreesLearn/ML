#from highlight import *

n = int(input())
p = list(map(int, input().split()))
remaining = set(range(1, n+1))

a = []
# 0 = even, 1 = odd, -1 = missing

for i in p:
    if i == 0:
        a.append(-1)
    else:
        remaining.remove(i)
        if i % 2 == 0:
            a.append(0)
        else:
            a.append(1)

n_odd = 0
n_even = 0
for i in remaining:
    if i % 2 == 0:
        n_even += 1
    else:
        n_odd += 1

dp = [
    [
        [[float("inf"), float("inf")] for _ in range(n_even+1)]
        for _ in range(n_odd+1)
    ]
    for __ in range(n+1)
]
# dp[index][num_odd_used][num_even_used][last_parity] => min complexity

dp[0][0][0] = [0, 0]

#print(a)

for index in range(1, n+1):
    for num_odd_used in range(n_odd+1):
        for num_even_used in range(n_even+1):
            if a[index-1] == 0:
                dp[index][num_odd_used][num_even_used] = [
                    min(dp[index-1][num_odd_used][num_even_used][0], dp[index-1][num_odd_used][num_even_used][1] + 1),
                    float("inf")
                ]
            elif a[index-1] == 1:
                dp[index][num_odd_used][num_even_used] = [
                    float("inf"),
                    min(dp[index-1][num_odd_used][num_even_used][0] + 1, dp[index-1][num_odd_used][num_even_used][1]),
                ]
            else:
                dp[index][num_odd_used][num_even_used] = [
                    min(dp[index-1][num_odd_used][num_even_used-1][0], dp[index-1][num_odd_used][num_even_used-1][1] + 1),
                    min(dp[index-1][num_odd_used-1][num_even_used][0] + 1, dp[index-1][num_odd_used-1][num_even_used][1]),
                ]
print(min(dp[n][n_odd][n_even]))