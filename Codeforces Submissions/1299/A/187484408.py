n = int(input())
a = list(map(int,input().split()))
bits = [0]*30
for i in a:
    x = 1
    for j in range(30):
        if i&x:
            bits[j] += 1
        x *= 2
z = -1
for i in range(29,-1,-1):
    if bits[i] == 1:
        z = i
        break
if z >= 0:
    x = 2**z
    for i in a:
        if x&i:
            break
    l = [i]
    for j in a:
        if j != i:
            l.append(j)
    print(*l)
else:
    print(*a)