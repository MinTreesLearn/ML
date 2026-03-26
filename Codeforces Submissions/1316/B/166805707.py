def find(S,N,k):
    ans = S[k-1:]
    if len(ans)%2==0:
        ans+=S[:k-1]
    else:
        ans+=S[:k-1][::-1]
    return ans
for _ in range(int(input())):
    N = int(input())
    S = input()
    ans = [[S,1]]
    for k in range(2,N+1):
        ans.append([find(S,N,k),k])
    ans.sort()
    print(ans[0][0])
    print(ans[0][1])
