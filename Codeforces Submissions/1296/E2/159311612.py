n=int(input())
s=input()
dp=[0]*n
maxdp=[0]*26
for i in range(n):
    dp[i]=1
    for j in range(ord(s[i])-ord("a")+1,26):
        dp[i]=max(dp[i],maxdp[j]+1)
    maxdp[ord(s[i])-ord("a")]=dp[i]
print(max(maxdp))
print(*dp)