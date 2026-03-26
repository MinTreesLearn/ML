import sys, collections, math, bisect, heapq, random, functools
input = sys.stdin.readline
out = sys.stdout.flush

def solve():
    H,n = map(int,input().split())
    a = list(map(int,input().split()))

    pre = [0]
    pos = -1
    minv = float('inf')
    for i in range(n):
        pre.append(pre[-1] + a[i])
        minv = min(minv,pre[-1])
    if pre[-1] >= 0:
        if minv + H > 0:
            print(-1)
        else:
            for i in range(1,n + 1):
                if pre[i] + H <= 0:
                    print(i)
                    break
    else:
        v = H + minv
        if v <= 0:
            for i in range(1,n + 1):
                if pre[i] + H <= 0:
                    print(i)
                    break
        else:
            round = v // (-pre[-1]) if v % (-pre[-1]) == 0 else v // (-pre[-1]) + 1
            ans = H + round * pre[-1]
            for i in range(1,n + 1):
                if ans + pre[i] <= 0:
                    print(n * round + i)
                    break




if __name__ == '__main__':
        solve()