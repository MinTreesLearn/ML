
n = int(input())

a = list(map(int,input().split()))
t = list(map(int,input().split()))

ta = []

for i in range(n):
    ta.append([t[i],a[i]])
ta.sort()
ta.reverse()

ndic = {}

ans = 0
for t,a in ta:

    now = a
    tempq = []
    while now in ndic:
        tempq.append(now)
        now = ndic[now]

    for i in tempq:
        ndic[i] = now + 1

    ndic[now] = now + 1

    ans += (now - a) * t

print (ans)
        

        
            
