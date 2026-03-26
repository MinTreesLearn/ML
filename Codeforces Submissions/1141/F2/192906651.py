from collections import defaultdict


n = int(input())
arr = list(map(int, input().split()))

pre = [0]*(n+1)
for i in range(n):
    pre[i+1] = pre[i] + arr[i]

mp = defaultdict(list)

for i in range(n):
    for j in range(i,n):
        sum = pre[j+1] - pre[i]
        mp[sum].append((i,j))

k = 0
ans = None 
qs = None
for x, v in mp.items():
    v.sort(key=lambda p: p[1])

    temp = 1
    right = v[0][1]
    q = [v[0]]
    for i in range(1,len(v)):
        if(v[i][0] > right):
            temp += 1
            right = v[i][1]
            q.append(v[i])

    # print(x, v, temp)
    if(temp > k):
        ans = x
        k = temp
        qs = q
print(k)
# print(qs)
for x,y in qs:
    print(x+1, y+1)
