s=input()
dp=[[0]*(26) for _ in range(len(s)+1)]
for i in range(len(s)):
    ch=ord(s[i])-ord("a")
    dp[i+1][ch]+=1
    for j in range(26):
        dp[i+1][j]+=dp[i][j]
for _ in range(int(input())):
    l,r=map(int,input().split())
    cnt=0
    for j in range(26):
        cnt+=int(dp[r][j]-dp[l-1][j])>0
    if (l==r or cnt>=3 or s[l-1]!=s[r-1]):
        print("Yes")
    else:
        print("No")
    