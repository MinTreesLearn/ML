import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[list(map(int,input().split())) for i in range(n)]
ans=0
for j in range(m):
    idx={}
    for i in range(n):
        idx[i*m+(j+1)]=i
    score_cyc=10**18
    # up
    r=0
    cyc=[0]*n
    for i in range(n):
        if a[i][j] not in idx:
            r+=1
        else:
            dist=i-idx[a[i][j]] if idx[a[i][j]]<=i else n+i-idx[a[i][j]]
            cyc[dist%n]+=1
    for i in range(n):
        score_cyc=min(score_cyc,i+(n-cyc[i]-r)+r)
    ans+=score_cyc
print(ans)