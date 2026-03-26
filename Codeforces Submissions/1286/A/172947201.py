import sys, random
input = lambda : sys.stdin.readline().rstrip()


write = lambda x: sys.stdout.write(x+"\n"); writef = lambda x: print("{:.12f}".format(x))
debug = lambda x: sys.stderr.write(x+"\n")
YES="Yes"; NO="No"; pans = lambda v: print(YES if v else NO); INF=10**18
LI = lambda : list(map(int, input().split())); II=lambda : int(input()); SI=lambda : [ord(c)-ord("a") for c in input()]
def debug(_l_):
    for s in _l_.split():
        print(f"{s}={eval(s)}", end=" ")
    print()
def dlist(*l, fill=0):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [dlist(*ll, fill=fill) for _ in range(l[0])]

n = int(input())
a = list(map(int, input().split()))
odd = (n+1)//2
even = n//2
num = 0
for v in a:
    if v==0:
        num += 1
    else:
        if v%2:
            odd -= 1
        else:
            even -= 1
dp = [[INF]*(odd+1) for _ in range(2)]
dp[0][0] = dp[1][0] = 0
for v in a:
    ndp = [[INF]*(odd+1) for _ in range(2)]
    for i in range(odd+1):
        if v==0:
            ndp[0][i] = min(dp[0][i], dp[1][i]+1)
            if i>0:
                ndp[1][i] = min(dp[0][i-1]+1, dp[1][i-1])
        elif v%2==1:
            ndp[0][i] = INF
            ndp[1][i] = min(dp[0][i]+1, dp[1][i])
        else:
            ndp[0][i] = min(dp[0][i], dp[1][i]+1)
            ndp[1][i] = INF
    dp = ndp
#     print(dp)
ans = min(dp[0][odd], dp[1][odd])
print(ans)