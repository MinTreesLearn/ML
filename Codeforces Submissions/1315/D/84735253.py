import heapq
n = int(input())
A = [int(i) for i in input().split()]
T = [int(i) for i in input().split()]
AT = [A[i]*(10**6)+T[i] for i in range(n)]
AT.sort()
aa, tt = 0, 0
ans = 0
H = []
for at in AT:
    a, t = at//(10**6), at % (10**6)
    if a == aa:
        heapq.heappush(H, -t)
        tt += t
    else:
        while H and aa < a:
            tm = heapq.heappop(H)
            tt += tm
            ans += tt
            aa += 1
        heapq.heappush(H, -t)
        aa = a
        tt += t
while H:
    tm = heapq.heappop(H)
    tt += tm
    ans += tt
print(ans)
