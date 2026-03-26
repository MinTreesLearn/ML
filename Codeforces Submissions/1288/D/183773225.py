n,m = [int(i) for i in input().strip().split()]
a = [[int(i) for i in input().strip().split()] for j in range(n)]
lo = float('inf')
hi = -float('inf')
val = (2**m)-1
ans = [None,None]
for i in range(n):
    lo = min(lo,min(a[i]))
    hi = max(hi,max(a[i]))
while lo<=hi:
    x = (lo+hi)//2
    already = set()
    masks = []
    for i in range(n):
        mask = int(''.join(['1' if a[i][k]>=x else '0' for k in range(m)]),2)
        if mask in already:
            continue
        else:
            already.add(mask)
            masks.append([mask,i])
    N = len(masks)
    check = False
    for i in range(N):
        for j in range(i,N):
            if masks[i][0]|masks[j][0]==val:
                check = True
                ans = [masks[i][1],masks[j][1]]
                break
        if check:
            break
    if check:
        lo = x+1
    else:
        hi = x-1
print(ans[0]+1,ans[1]+1)