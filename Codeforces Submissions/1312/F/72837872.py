import sys
readline = sys.stdin.buffer.readline

T = int(readline())
Ans = [None]*T

for qu in range(T):
    N, x, y, z = map(int, readline().split())
    A = list(map(int, readline().split()))
    ts = 200
    dp = [[0]*3 for _ in range(ts)]
    table = [[[0]*4 for _ in range(3)] for _ in range(ts+8)]

    for hp in range(ts):
        if 0 < hp <= x:
            table[hp][0][0] = 1
            table[hp][1][0] = 1
            table[hp][2][0] = 1
        if 0 < hp <= y:
            table[hp][0][0] = 1
            table[hp][2][0] = 1
        if 0 < hp <= z:
            table[hp][0][0] = 1
            table[hp][1][0] = 1
        for ty in range(3):
            dp[hp][ty] = table[hp][ty].index(0)
        
        
        val0 = dp[hp][0]
        val1 = dp[hp][1]
        val2 = dp[hp][2]
        
        table[hp+x][0][val0] = 1
        table[hp+x][1][val0] = 1
        table[hp+x][2][val0] = 1
        table[hp+y][0][val1] = 1
        table[hp+y][2][val1] = 1
        table[hp+z][0][val2] = 1
        table[hp+z][1][val2] = 1
    
    cl = None
    for loop in range(10, 61):
        for i in range(loop):
            if dp[ts-1-i] != dp[ts-1-i-loop]:
                break
        else:
            cl = loop
            break
        continue
    
    A1 = [None]*N
    for i in range(N):
        a = A[i]
        if a < ts:
            A1[i] = a
        else:
            k = 1 + (a-ts)//cl
            A1[i] = a - k*cl
    

    xx = 0
    for a in A1:
        xx ^= dp[a][0]
    res = 0
    for a in A1:
        da = dp[a][0]
        if dp[max(0, a-x)][0]^da == xx:
            res += 1
        if dp[max(0, a-y)][1]^da == xx:
            res += 1
        if dp[max(0, a-z)][2]^da == xx:
            res += 1
    Ans[qu] = res
print('\n'.join(map(str, Ans)))
