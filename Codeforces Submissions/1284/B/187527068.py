from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))


def answer():


    minv , maxv = [] , []
    canPair , ans = n , 0
    for x in range(n):

        ok , m = False , float('inf')
        for i in range(1 , a[x][0] + 1):
            m = min(m , a[x][i])
            if(m < a[x][i]):
                ok = True
                break

        if(ok):
            ans += 2 * canPair - 1
            canPair -= 1
        else:
            minv.append(min(a[x][1:]))
            maxv.append(max(a[x][1:]))


    j = 0
    minv.sort()
    maxv.sort()
    for i in range(len(minv)):
        while(j < len(maxv) and maxv[j] <= minv[i]):
            j += 1

        ans += len(maxv) - j


    return ans
        

for T in range(1):

    n = int(input())
    a = [inp() for i in range(n)]


    print(answer())
