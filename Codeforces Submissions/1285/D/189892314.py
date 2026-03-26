n = int(input())
a = list(map(int, input().split()))
m = len(bin(max(a)))-2


def solve(i=m, l=0, r=n-1):
    if i == -1:
        return 0
    
    k = l
    y = 1 << i
    for j in range(l, r+1):
        if a[j] & y == 0:
            a[j], a[k] = a[k], a[j]
            k += 1
    
    z = -1
    for j in range(l, r+1):
        if a[j] & y:
            z = j
            break
    
    if z in (l, -1):
        return solve(i-1, l, r)

    return min(solve(i-1, l, z-1), solve(i-1, z, r)) + y

print(solve())