import sys
input = lambda :sys.stdin.readline()[:-1]
ni = lambda :int(input())
na = lambda :list(map(int,input().split()))
yes = lambda :print("yes");Yes = lambda :print("Yes");YES = lambda : print("YES")
no = lambda :print("no");No = lambda :print("No");NO = lambda : print("NO")
#######################################################################

for _ in range(ni()):
    n, x = na()
    s = input()
    z = [0]
    for i in range(n):
        if s[i]=="0":
            z.append(z[-1]+1)
        else:
            z.append(z[-1]-1)
    if z[-1] == 0:
        if x in z:
            print(-1)
        else:
            print(0)
        continue

    ans = 0
    p = z[-1]
    q = p // abs(p)
    for i in range(n):
        if (x-z[i])%p==0 and (z[i]-x)*q <= 0:
            ans += 1
    print(ans)
