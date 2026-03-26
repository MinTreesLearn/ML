N = int(input())
A = list(map(int,input().split()))

ans = []
for i in range(N):
    k = A[:]
    num = A[i]
    for l in range(i-1,-1,-1):
        num = min(num,k[l])
        k[l] = num
    num = A[i]
    for r in range(i+1,N):
        num = min(num,k[r])
        k[r] = num
    ans.append([sum(k),k,i])
ans.sort(reverse=True)
print(*ans[0][1])


