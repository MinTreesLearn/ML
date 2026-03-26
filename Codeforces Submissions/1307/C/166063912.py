S = input()
N = len(S)
cnt = [0]*26
dp = [[0]*26 for j in range(26)]
for i in range(N):
    ch = ord(S[i]) - 97
    for j in range(26):
        dp[j][ch] += cnt[j]
    cnt[ch] += 1

res = max(cnt)
for i in range(26):
    res = max(res, max(dp[i]))
print(res)