from sys import stdin
input = stdin.readline


def solve(i , prev):

    if(i == n):return 0
    if(dp[i][prev] != -1):return dp[i][prev]

    ans , minus = 0 , 1
    for j in range(i , n):

        if(prev == value[i][j]):
            ans = max(ans , solve(j + 1 , prev + 1) + minus)

        minus += 1

    ans = max(ans , solve(i + 1 , a[i]))

    dp[i][prev] = ans
    return ans

def answer():

    global dp , value

    value = [[-1 for i in range(n)] for j in range(n)]

    for i in range(n):
        value[i][i] = a[i]


    for i in range(n - 1 , -1 , -1):
        for j in range(i + 1 , n):

            for k in range(i , j):

                if(value[i][k] == -1 or value[k + 1][j] == -1):continue

                if(value[i][k] == value[k + 1][j]):
                    value[i][j] = value[i][k] + 1


    dp = [[-1 for i in range(1501)] for i in range(n)]
    ans = solve(0 , 0)

    return n - ans
    
for T in range(1):

    n = int(input())
    a = list(map(int,input().split()))

    print(answer())
