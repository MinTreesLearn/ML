import sys, collections, math, bisect, heapq, random, functools
input = sys.stdin.readline
out = sys.stdout.flush

def solve():
    n = int(input())
    left = input().rstrip('\n')
    right = input().rstrip('\n')
    c1,c2 = collections.defaultdict(list),collections.defaultdict(list)
    c1i,c2i = [],[]
    for i in range(n):
        c11 = left[i]
        c22 = right[i]
        if c11 == '?':
            c1i.append(i + 1)
        else:
            c1[c11].append(i + 1)
        if c22 == '?':
            c2i.append(i + 1)
        else:
            c2[c22].append(i + 1)
    ans = []
    for c in c1:
        while c1[c] and c2[c]:
            l,r = c1[c].pop(-1),c2[c].pop(-1)
            ans.append([l,r])
        if c1[c]:
            while c1[c] and c2i:
                l,r = c1[c].pop(-1), c2i.pop(-1)
                ans.append([l, r])
    for c in c2:
        while c1[c] and c2[c]:
            l,r = c1[c].pop(-1),c2[c].pop(-1)
            ans.append([l,r])
        if c2[c]:
            while c2[c] and c1i:
                r,l = c2[c].pop(-1), c1i.pop(-1)
                ans.append([l, r])
    posa,posb = [],[]
    for c in c1:
        posa.extend(c1[c])
    for c in c2:
        posb.extend(c2[c])

    while c1i:
        if not posb and not c2i:
            break
        while c1i and posb:
            l,r = c1i.pop(-1),posb.pop(-1)
            ans.append([l,r])
        while c1i and c2i:
            l,r = c1i.pop(-1),c2i.pop(-1)
            ans.append([l,r])
    while c2i:
        if not posa and not c1i:
            break
        while c2i and posa:
            r,l = c2i.pop(-1),posa.pop(-1)
            ans.append([l,r])
        while c1i and c2i:
            l,r = c1i.pop(-1),c2i.pop(-1)
            ans.append([l,r])


    print(len(ans))

    for l,r in ans:
        print(l,r)









if __name__ == '__main__':
        solve()