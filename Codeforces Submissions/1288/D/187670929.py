from sys import stdin

N,M = map(int,stdin.readline().split())
ARRS = [list(map(int,stdin.readline().split())) for i in range(N)]

def test(x):
    bitmasks = dict()

    for i,row in enumerate(ARRS):
        key = tuple(1 if num >= x else 0 for num in row)

        if key not in bitmasks:
            bitmasks[key] = i+1

    bitmasks = list(bitmasks.items())

    for i in range(len(bitmasks)):
        for j in range(i,len(bitmasks)):
            mask1,i1 = bitmasks[i]
            mask2,i2 = bitmasks[j]

            if all(b1 or b2 for b1,b2 in zip(mask1,mask2)):
                return True,i1,i2

    return False,None,None

l,r = 0,10**9
ans = None

while l <= r:
    m = (l+r)//2
    works,i,j = test(m)

    if works:
        l = m+1
        ans = i,j
    else:
        r = m-1

print(*ans)