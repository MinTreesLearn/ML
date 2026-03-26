def left(p,x):
    n = len(p)
    l,r = 0,n-1
    if p[l] == x:
        return 0
    while l<=r:
        mid = (l+r)//2
        if p[mid]<x:
            if mid != n-1:
                if p[mid+1] >= x:
                    return mid+1
                else:
                    l = mid+1
            else:
                return mid+1
        else:
            r = mid-1
        
n = int(input())
s = 0
f,la = [],[]
for _ in range(n):
    l = list(map(int,input().split()))
    q = l.pop(0)
    for i in range(q-1):
        if l[i+1]>l[i]:
            s += n
            break
    else:
        f.append(l[0])
        la.append(l[-1])
        
# print(s,la,f)
f.sort()
la.sort()
y = n-len(f)
# print(f,la)
for i in f:
    s += left(la,i)
    # print(left(la,i))
    s += y
print(s)



