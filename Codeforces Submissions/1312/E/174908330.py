from sys import stderr
N = 505

dp1 = [N*[-1] for _ in range(N)]
dp2 = N*[int(1e9)]

def calculate1():
    for l in range(n):
        dp1[l][l+1] = a[l]

    for d in range(2,n+1):
        for l in range(n+1-d):
            r = l + d
            for mid in range(l+1, r):
                lf = dp1[l][mid]
                rg = dp1[mid][r]
                if lf > 0 and lf == rg:
                    dp1[l][r] = lf + 1
                    break
    #print('\n'.join(map(lambda x: str(x[:n+1]), dp1[:n+1])))

def calculate2():
    dp2[0] = 0
    for i in range(n):
        for j in range(i+1,n+1):
            if dp1[i][j] != -1:
                dp2[j] = min(dp2[j], dp2[i]+1)
    print(dp2[n])
    #print(dp2[:n+1])


n = int(input())
a = list(map(int, input().split()))
limit = 1000
i = 0
print(" ".join(map(str, a[i*limit:(i+1)*limit])), file=stderr)
calculate1()
calculate2()

