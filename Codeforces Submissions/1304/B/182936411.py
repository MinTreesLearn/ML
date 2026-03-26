def solve():
    n,m = list(map(int,input().split()))
    arr, pairs, single = [],[],[]
    ans = ''
    for i in range(n):
        arr.append(input())
    while arr:
        a = arr.pop()
        if a[::-1] in arr: # can be optimized with dict lookup
            pairs.append(a)
        else:
            single.append(a)
    while single:
        b = single.pop()
        if b[::-1] == b:
            ans = b
            break
    for i in pairs:
        ans = i + ans + i[::-1]
    print(len(ans))
    return ans
print(solve())