from collections import deque
N,M,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

def count(w):
    l = deque(B[:w])
    num = l.count(0)
    ans = 0
    for i in range(w,M):
        if num==0:ans += 1
        if l.popleft()==0:num-=1
        if B[i]==0:num+=1
        l.append(B[i])
    if num==0:ans += 1
    return ans


l = [0]*(N+1)
num = 0
for i in range(1,N+1):
    if K%i==0 and K//i<=M:
        h,w = i,K//i
        l[h]+=count(w)

num = 0
k = [0]*(N+1)
for i in range(1,N+1):
    num += l[i]
    k[i] += num+k[i-1]

ans = 0
num = 0
for x in range(N):
    if A[x]==1:
        num+=1
    elif num!=0:
        ans += k[num]
        num = 0
if num!=0:
    ans += k[num]
print(ans)
