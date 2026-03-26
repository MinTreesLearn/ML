n = int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
delta=sorted([ai-bi for ai,bi in zip(a,b)],reverse=True)
# (ai-bi)+(aj-bj)>0

l,r=0,n-1
cnt=0
ct=n-1
while l<r:
    if delta[l]+delta[r]>0:
        cnt+=ct
        ct-=1
        l+=1
    else:
        ct-=1
        r-=1

print(cnt)

