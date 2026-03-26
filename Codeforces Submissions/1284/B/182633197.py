n = int(input())
ans = 0
mx = [0] * (10 ** 6 + 5)
mn = []
koltrue = 0
for _ in range(n):
    l = list(map(int, input().split()))
    mnn = l[1]
    mxx = l[1]
    t = False
    for i in range(2, l[0] + 1):
        if l[i-1] < l[i]:
            t = True
        mnn = min(mnn, l[i])
        mxx = max(mxx, l[i])
    
    if t:
        koltrue += 1
        mn.append('t')
    else:
        mn.append(mnn)
        mx[mxx] += 1
#print(koltrue)
sufs = [0] * (10 ** 6 + 5)
for i in range(len(sufs) - 2, -1, -1):
    sufs[i] = mx[i] + sufs[i+1]
#print(sufs[:10])
#print(mn)
for i in range(len(mn)):
    if mn[i] == 't':
        ans += n
    else:
        ans += koltrue
        #print('#', mn[i], i)
        ans += sufs[mn[i] + 1]
        #print(ans)
print(ans)
        

# Thu Nov 24 2022 20:38:24 GMT+0300 (Moscow Standard Time)

# Sat Nov 26 2022 14:10:03 GMT+0300 (Moscow Standard Time)
