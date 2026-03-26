def solve():
    n,m = list(map(int,input().split()))
    arr, pairs, single = [],[],[]
    ans = ''
    lookup = dict()
    for i in range(n):
        word = input()
        arr.append(word)
        lookup[word] = 1
    for a in arr:
        try:
            if lookup[a[::-1]] and a != a[::-1]:
                pairs.append(a)
                lookup[a[::-1]] = 0
                lookup[a] = 0
            else:
                single.append(a)
        except KeyError:
            single.append(a)
    for a in single:
        if a == a[::-1]:
            ans = a
            break
    for i in pairs:
        ans = i + ans + i[::-1]
    print(len(ans))
    return ans
print(solve())