import sys
input = sys.stdin.readline

N, M = map(int, input().split())

ans = [1, 2]
tmp = 0
ind = 3
while tmp < M:
    t = (ind-1)//2
    if tmp + t <= M:
        ans.append(ind)
        tmp += t
        ind += 1
    else:
        delta = M-tmp
        ans.append(ind-1+(ind-2*delta))
        break

if M == 0:
    if N == 1:
        ans = [1]

if len(ans) > N:
    print(-1)
else:
    rem = []
    last = ans[-1]
    tmp = 10**9
    for _ in range(N-len(ans)):
        rem.append(tmp)
        tmp -= last+1
    ans = ans + rem[::-1]
    print(*ans)