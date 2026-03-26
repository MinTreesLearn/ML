import sys, collections, math,bisect
input = sys.stdin.readline

n = int(input())
s = input().rstrip('\n')
max_v = 0
dp = [0] * 26
ans = [0] * n
for i in range(n):
    temp = 0
    for j in range(26):
        if j > ord(s[i]) - ord('a'):
            temp = max(dp[j],temp)
    ans[i] = temp + 1
    max_v = max(max_v,temp + 1)
    dp[ord(s[i]) - ord('a')] = max(dp[ord(s[i]) - ord('a')],temp + 1)
print(max_v)
print(*ans)

















