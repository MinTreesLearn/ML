import sys
input=sys.stdin.readline
s=list(input().rstrip())
n=len(s)
cnt=[[0]*(n+1) for i in range(26)]
for i in range(1,n+1):
    cnt[ord(s[i-1])-ord("a")][i]+=1
    for j in range(26):
        cnt[j][i]+=cnt[j][i-1]
q=int(input())
for _ in range(q):
    l,r=map(int,input().split())
    if s[r-1]!=s[l-1]:
        print("Yes")
        continue
    if r-l+1==1:
        print("Yes")
        continue
    flag=0
    for i in range(26):
        flag+=(cnt[i][r]-cnt[i][l-1]>0)
    if flag>=3:
        print("Yes")
    else:
        print("No")