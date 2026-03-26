import sys, collections, math, bisect, heapq, random, functools
input = sys.stdin.readline
out = sys.stdout.flush
def dp(a):
    n = len(a)
    d = [1] * n
    pre = [-1] * n
    for i in range(1,n):
        for j in range(i):
            if a[i][0] > a[j][1]:
                if d[j] + 1 > d[i]:
                    d[i] = d[j] + 1
                    pre[i] = j
    maxv,pos = -float('inf'),-1
    for i in range(n):
        if maxv < d[i]:
            maxv = d[i]
            pos = i

    ans = []
    while pos != -1:
        ans.append([a[pos][0] + 1,a[pos][1] + 1])
        pos = pre[pos]
    return maxv,ans


def solve():
    n = int(input())
    a = list(map(int,input().split()))
    pre = {-1:0}
    t = 0
    sel = collections.defaultdict(list)
    for i in range(n):
        t += a[i]
        for j in range(-1,i):
            v = t - pre[j]
            sel[v].append([j + 1,i])
        pre[i] = t

    can,maxv = [],[]
    for c in sel:
        v,d = dp(sel[c])
        can.append(d)
        maxv.append(v)
    pos = -1
    v = -float('inf')
    for i in range(len(maxv)):
        if v < maxv[i]:
            v = maxv[i]
            pos = i
    print(v)
    for l,r in can[pos]:
        print(l,r)


    


if __name__ == '__main__':

        solve()