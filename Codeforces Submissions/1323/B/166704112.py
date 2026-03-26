def helper(arr):
    res=[0]*(len(arr)+1)
    i=0
    while i<len(arr):
        if arr[i]==0:
            i+=1
        else :
            j=i
            while (j<len(arr) and arr[j]==1):
                j+=1
            for l in range(1,j-i+1):
                res[l]+=j-i-l+1
            i=j
    return res[:]
                
n,m,k=map(int,input().split())
arr=list(map(int,input().split()))
brr=list(map(int,input().split()))
ga=helper(arr)
gb=helper(brr)
ans=0
# print(ga,gb)
for i in range(1,len(ga)):
    if k%i==0 and k//i<=m:
        # print(i,k//i)
        ans+=ga[i]*gb[k//i]
print(ans)